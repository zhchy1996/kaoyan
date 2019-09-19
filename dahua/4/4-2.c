// 两栈共用空间
#include "head.c"

// 定义结构
typedef struct
{
  ElemType data[MAXSIZE];
  int top1;
  int top2;
} SqStack;

// 初始化
Status CreatSqStack(SqStack *S)
{
  S->top1 = -1;
  S->top2 = MAXSIZE;
  return OK;
}

// 打印
void print(SqStack S)
{
  while (S.top1 > -1)
  {
    printf("stack 1 top %d is %5d\n", S.top1, S.data[S.top1]);
    S.top1--;
  }
  while (S.top2 < MAXSIZE)
  {
    printf("stack 2 top %d is %5d\n", S.top2, S.data[S.top2]);
    S.top2++;
  }
}

// 进栈
Status Push(SqStack *S, ElemType e, int num)
{
  if (num == 1)
  {
    if (S->top1 + 1 == S->top2)
      return ERROR;
    S->data[++S->top1] = e;
  }
  else if (num == 2)
  {
    if (S->top2 - 1 == S->top1)
      return ERROR;
    S->data[--S->top2] = e;
  }
  return OK;
}

// 出栈
Status Pop(SqStack *S, ElemType *e, int num)
{
  if (num == 1)
  {
    if (S->top1 == 0)
      return ERROR;
    *e = S->data[S->top1];
    S->top1--;
  }
  if (num == 2)
  {
    if (S->top2 == MAXSIZE - 1)
      return ERROR;
    *e = S->data[S->top2];
    S->top2++;
  }
  return OK;
}

int main()
{
  SqStack S;
  ElemType e;
  CreatSqStack(&S);
  for (int i = 0; i < 10; i++)
  {
    Push(&S, i, 1);
  }
  for (int i = 0; i < 10; i++)
  {
    Push(&S, i, 2);
  }
  Pop(&S, &e, 2);
  print(S);
  printf("pop element is %d\n", e);
  return 0;
}