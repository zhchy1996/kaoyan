#include "head.c"

typedef struct
{
  VType VArr[MAXSIZE];
  EdgeType EArr[MAXSIZE][MAXSIZE];
  int VNum, ENum;
} MGraph;

Status InitM(MGraph *M)
{
  M->VNum = 0;
  M->ENum = 0;
  return OK;
}

Status CreateM(MGraph *M)
{
  int i, j, k, m;
  printf("输入顶点数和边数：\n");
  scanf("%d %d", &M->VNum, &M->ENum);
  // 初始化顶点数组
  for (i = 0; i < M->VNum; i++)
  {
    printf("请输入%d顶点值\n", i);
    scanf("\n%c", &M->VArr[i]);
  }
  // 初始化邻接矩阵
  for (i = 0; i < M->VNum; i++)
    for (j = 0; j < M->VNum; j++)
      M->EArr[i][j] = INFINITY;
  for (k = 0; k < M->ENum; k++)
  {
    printf("请输入边(i,j)的值和权\n");
    scanf("\n%d %d %d", &i, &j, &m);
    M->EArr[i][j] = m;
    M->EArr[j][i] = m;
  }
  return OK;
}

Status print(MGraph M)
{
  int i, j;
  for (i = 0; i < M.VNum; i++)
    printf("%10c", M.VArr[i]);
  for (i = 0; i < M.VNum; i++)
  {
    printf("\n");
    for (j = 0; j < M.VNum; j++)
      printf("%10d", M.EArr[i][j]);
  }
  printf("\n");
}

int main()
{
  MGraph M;
  CreateM(&M);
  print(M);
  return 0;
}