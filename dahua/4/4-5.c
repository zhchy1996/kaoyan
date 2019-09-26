#include "head.c"
#define MAXSIZE 11

typedef struct
{
  ElemType data[MAXSIZE];
  int front;
  int rear;
} SqQueue;

// 创建
Status CreateSqQueue(SqQueue *S)
{
  S->front = 0;
  S->rear = 0;
  return OK;
}
// 打印
void print(SqQueue S)
{
  int p = S.front;
  while (p != S.rear)
  {
    printf("%d is %d\n", p, S.data[p]);
    p = (p + 1) % MAXSIZE;
  }
}

// 长度
int QueueLength(SqQueue S)
{
  return (S.rear - S.front + MAXSIZE) % MAXSIZE;
}

// 插入
Status QueueInsert(SqQueue *S, ElemType e)
{
  // 判断是否已满
  if ((S->rear + 1) % MAXSIZE == S->front)
    return ERROR;
  S->data[S->rear] = e;
  S->rear = (S->rear + 1) % MAXSIZE;
  return OK;
}

// 取出
Status QueuePop(SqQueue *S, ElemType *e)
{
  if (S->front == S->rear)
    return ERROR;
  *e = S->data[S->front];
  S->front = (S->front + 1) % MAXSIZE;
  return OK;
}

int main()
{
  SqQueue S;
  ElemType e;
  CreateSqQueue(&S);
  for (int i = 0; i < 10; i++)
  {
    QueueInsert(&S, i);
  }
  QueuePop(&S, &e);
  print(S);
  return 0;
}
