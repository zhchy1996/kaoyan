#include "head.c"
// 声明结构
typedef struct Node
{
  ElemType data;
  struct Node *next;
} Node, *LinkList;

// 返回第i个元素
Status GetElem(LinkList L, int i, ElemType *e)
{
  int j = 1;
  LinkList p = L->next;
  while (p && j < i)
  {
    p = p->next;
    j++;
  }
  if (!p)
  {
    return ERROR;
  }
  *e = p->data;
  return OK;
}

// 在位置i插入节点
Status ListInsert(LinkList *L, int i, ElemType e)
{
  int j = 1;
  LinkList s, p = *L;
  while (p && j < i)
  {
    p = p->next;
    j++;
  }
  if (!p)
  {
    return ERROR;
  }
  s = (LinkList)malloc(sizeof(ElemType)); // 开辟储存节点的区域
  s->data = e;
  s->next = p->next; // 插入节点核心
  p->next = s;
  return OK;
}

// 删除第i个节点
Status ListDelect(LinkList *L, int i, ElemType *e)
{
  int j = 1;
  LinkList q, p = *L;
  while (p && j < i)
  {
    p = p->next;
    j++;
  }
  if (!(p->next))
  {
    return ERROR;
  }
  q = p->next;
  p->next = q->next;
  *e = q->data;
  free(q);
  return OK;
}

// 创建链表(头插法)
void CreateListHead(LinkList *L, int n)
{
  LinkList p;
  int i;
  *L = (LinkList)malloc(sizeof(Node));
  (*L)->next = NULL;
  for (i = 0; i < n; i++)
  {
    p = (LinkList)malloc(sizeof(Node));
    p->data = i + 1;
    p->next = (*L)->next;
    (*L)->next = p;
  }
}

// 创建链表（尾插法）
void CreateListTail(LinkList *L, int n)
{
  int i;
  LinkList p, r;
  *L = (LinkList)malloc(sizeof(Node));
  r = *L;
  for (i = 0; i < n; i++)
  {
    p = (LinkList)malloc(sizeof(Node));
    p->data = i + 1;
    r->next = p;
    r = p;
  }
  r->next = NULL;
}

// 打印
void print(LinkList L)
{
  int i = 0;
  while (L)
  {
    printf("第%d个为%d\n", i, L->data);
    L = L->next;
    i++;
  }
}

// 整表删除
Status ClearList(LinkList *L)
{
  LinkList p, q;
  p = (*L)->next;
  while (p)
  {
    q = p->next;
    free(p);
    p = q;
  }
  (*L)->next = NULL;
  return OK;
}

int main()
{
  LinkList L;
  ElemType e;
  CreateListTail(&L, 10);
  // ListInsert(&L, 5, 11);
  // ListDelect(&L, 5, &e);
  ClearList(&L);
  print(L);
  return 0;
}