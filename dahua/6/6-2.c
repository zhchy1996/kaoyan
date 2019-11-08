#include "head.c"

// 边表
typedef struct EdgeNode
{
  int VI;
  EdgeType weight;
  struct EdgeNode *next;
} EdgeNode;

// 顶点表节点
typedef struct VNode
{
  VType data;
  EdgeNode *firstEdge;
} VNode, VArr[MAXSIZE];

typedef struct MGraph
{
  VArr vArr;
  int VNum, ENum;
} MGraph;

Boolean visited[MAXSIZE];

Status CreatE(MGraph *G, int i, int j, int w);

Status CreatMGraph(MGraph *G)
{
  int i, j, k, w;

  printf("请输入节点数和边数\n");
  scanf("\n%d %d", &G->VNum, &G->ENum);
  for (i = 0; i < G->VNum; i++)
  {
    printf("请输入第%d个节点的值\n", i);
    scanf("\n%c", &G->vArr[i].data);
    G->vArr[i].firstEdge = NULL;
  }
  for (i = 0; i < G->ENum; i++)
  {
    printf("请输入G(i,j)的i,j和权\n");
    scanf("%d %d %d", &j, &k, &w);
    CreatE(G, j, k, w);
    CreatE(G, k, j, w);
  }
  return OK;
}

Status CreatE(MGraph *G, int i, int j, int w)
{
  EdgeNode *e;
  e = (EdgeNode *)malloc(sizeof(EdgeNode));
  e->next = G->vArr[i].firstEdge;
  e->VI = j;
  e->weight = w;
  G->vArr[i].firstEdge = e;
  return OK;
}

void print(MGraph G)
{
  int i = 0;
  EdgeNode *e;
  for (i = 0; i < G.VNum; i++)
  {
    printf("%2c", G.vArr[i].data);
    e = G.vArr[i].firstEdge;
    while (e)
    {
      printf("   -->   ");
      printf("%2d", e->VI);
      e = e->next;
    }
    printf("\n");
  }
}

void DFS(MGraph G, int i)
{
  visited[i] = TRUE;
  printf("%c  ", G.vArr[i].data);
  for (int i = 0; i++;)
}

int main()
{
  MGraph M;
  CreatMGraph(&M);
  print(M);
  return 0;
}