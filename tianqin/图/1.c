typedef struct
{
  int no;
  char info;
} VertexType;

// 图的定义
typedef struct
{
  int edges[maxSize][maxSize]; // 邻接矩阵定义，如果是有权图，将int改为float
  int n, e;                    // 存放定点数和边数
  VertexType vex[maxSize];
} MGraph;

// 邻接表
// 定义边结构
typedef struct ArcNode
{
  int adjvex;              // 该边指向结点的位置
  struct ArcNode *nextarc; // 指向下一条边信息
  int info;                // 该边的相关信息，如权值，这一句用的不多
} ArcNode;
// 定义顶点结构
typedef struct
{
  char data;
  ArcNode *firstarc; // 指向第一条边的指针
} VNode;
typedef struct
{
  VNode adjlist[maxSize]; //邻接表
  int n, e;               // 顶点数和边数
} AGraph;

// 深度优先遍历
int visited[maxSize];
void DFS(AGraph G, int n)
{

  visited[n] = 1;
  visit(G.adjlist[n]);
  ArcNode *p;
  p = G.adjlist[n].firstarc;
  while (p)
  {
    if (!visited[p->adjvex])
      DFS(G, visited[p->adjvex]);
    p = p->nextarc;
  }
}
