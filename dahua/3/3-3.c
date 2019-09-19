#include "head.c"

// 结构
typedef struct DulNode
{
  ElemType data;
  struct DulNode *prior;
  struct DulNode *next;
} DulNode, *DulList;

// 创建
Status CreateDulList(DulList *L, int n)
{
  int i = 0;
  DulList p, q;
  *L = (DulList)malloc(sizeof(DulNode));
  (*L)->next = *L;
  q = *L;
  while (i < n)
  {
    p = (DulList)malloc(sizeof(DulNode));
    p->data = i + 1;
    p->prior = (*L);
    p->next = (*L)->next;
    p->next->prior = p;
    (*L)->next = p;
    i++;
  }
  return OK;
}

// 打印
void print(DulList L)
{
  DulList p = L;
  int i = 1;
  p = L->next;
  while (p != L)
  {
    printf("第%d个为%d\n", i, p->data);
    p = p->next;
    i++;
  }
}

// 插入
Status ListInsert(DulList *L, int i, ElemType e)
{
  DulList p, q;
  int j = 0;
  p = *L;
  while (p && j < i)
  {
    p = p->next;
    j++;
  }
  if (!p)
  {
    return ERROR;
  }
  q = (DulList)malloc(sizeof(DulNode));
  q->data = e;
  p->prior->next = q; // 先将前驱的后指针指向新生成的元素
  q->prior = p->prior;
  p->prior = q;
  q->next = p;
  return OK;
}

// 删除
Status ListDelect(DulList *L, int i, ElemType *e)
{
  int j = 1;
  DulList p = (*L)->next;
  while (j < i)
  {
    p = p->next;
    ++j;
  }
  p->prior->next = p->next;
  p->next->prior = p->prior;
  *e = p->data;
  free(p);
  return OK;
}

int main()
{
  DulList L;
  ElemType e;
  CreateDulList(&L, 10);
  // ListInsert(&L, 1, e);
  ListInsert(&L, 5, 12);
  ListDelect(&L, 6, &e);
  print(L);
  return 0;
}