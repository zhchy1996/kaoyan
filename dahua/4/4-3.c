// 链栈
#include "head.c"

// 节点结构
typedef struct StackNode
{
  ElemType data;
  struct StackNode *next;
} StackNode, *LinkStackPr;

// 链栈
typedef struct LinkStack
{
  LinkStackPr top;
  int count;
} LinkStack;

// 创建
Status CreatLinkStack(LinkStack *L)
{
  L->count = 0;
  L->top = NULL;
  return OK;
}

// 入栈
Status Push(LinkStack *L, ElemType e)
{
  LinkStackPr p = (LinkStackPr)malloc(sizeof(StackNode));
  p->data = e;
  p->next = L->top;
  L->top = p;
  L->count++;
  return OK;
}

// 出栈
Status Pop(LinkStack *L, ElemType *e)
{
  LinkStackPr p;
  if (L->count < 1)
  {
    return ERROR;
  }
  p = L->top;
  *e = p->data;
  L->top = p->next;
  free(p);
  L->count--;
  return OK;
}

Status print(LinkStack L)
{
  LinkStackPr p;
  p = L.top;
  while (p)
  {
    printf("%d\n", p->data);
    p = p->next;
  }
  return OK;
}

int main()
{
  LinkStack L;
  ElemType e;
  CreatLinkStack(&L);
  for (int i = 0; i < 10; i++)
    Push(&L, i + 1);
  Pop(&L, &e);
  print(L);
  printf("popElement is %d\n", e);
  return 0;
}