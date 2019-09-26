#include "head.c"

typedef struct Node
{
  ElemType data;
  struct Node *next;

} Node, *QueuePtr;

typedef struct
{
  QueuePtr front, rear;
} LinkQueue;

Status creatLinkQueue(LinkQueue *Q)
{
  Q->front = Q->rear = (QueuePtr)malloc(sizeof(Node));
  Q->front->data = -1;
  Q->front->next = NULL;
  return OK;
}

void print(LinkQueue Q)
{
  QueuePtr S = Q.front->next;
  while (S)
  {
    printf("%d\n", S->data);
    S = S->next;
  }
}

Status InsertLinkQueue(LinkQueue *Q, ElemType e)
{
  QueuePtr S = (QueuePtr)malloc(sizeof(Node));
  S->next = NULL;
  S->data = e;
  Q->rear->next = S;
  Q->rear = S;
  return OK;
}

Status PopLinkQueue(LinkQueue *Q, ElemType *e)
{
  QueuePtr S = Q->front->next;
  *e = S->data;
  Q->front->next = S->next;
  if (Q->rear == S)
    Q->rear = Q->front;
  free(S);
  return OK;
}

int main()
{
  LinkQueue Q;
  ElemType e;
  creatLinkQueue(&Q);
  for (int i = 0; i < 3; i++)
  {
    InsertLinkQueue(&Q, i);
  }
  PopLinkQueue(&Q, &e);
  PopLinkQueue(&Q, &e);
  PopLinkQueue(&Q, &e);
  print(Q);
  return 0;
}