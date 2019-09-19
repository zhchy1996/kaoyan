// 顺序栈
#include "head.c"

// 定义结构
typedef struct
{
  ElemType data[MAXSIZE];
  int top;
} SqStack;

// 初始化
Status CreatSqStack(SqStack *S)
{
  S->top = -1;
  return OK;
}

// 打印
void print(SqStack S)
{
  while (S.top > -1)
  {
    printf("top %d is %5d\n", S.top, S.data[S.top]);
    S.top--;
  }
}

// 进栈
Status Push(SqStack *S, ElemType e)
{
  if (S->top == MAXSIZE - 1)
  {
    return ERROR;
  }
  S->top++;
  S->data[S->top] = e;
  return OK;
}

// 出栈
Status Pop(SqStack *S, ElemType *e)
{
  if (S->top == MAXSIZE - 1)
  {
    return ERROR;
  }
  *e = S->data[S->top];
  S->top--;
}

int main()
{
  SqStack S;
  ElemType e;
  CreatSqStack(&S);
  for (int i = 0; i < 10; i++)
  {
    Push(&S, i);
  }
  Pop(&S, &e);
  print(S);
  printf("pop element is %d\n", e);
  return 0;
}