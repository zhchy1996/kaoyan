#include <stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct
{
  ElemType data[MAXSIZE];
  int length;
} SqList;

// 根据索引获取元素
Status GetElem(SqList L, int i, ElemType *e)
{
  if (L.length == 0 || i < 1 || i > L.length)
  {
    return ERROR;
  }
  *e = L.data[i];
  return OK;
}

// 打印
Status print(SqList L)
{
  for (int i = 0; i < L.length; i++)
  {
    printf("data is %5d\n", L.data[i]);
  }
  printf("length is %d\n", L.length);
  return OK;
}

// 插入
Status ListInsert(SqList *L, int i, ElemType e)
{
  if (L->length == MAXSIZE)
  {
    return ERROR;
  }
  if (i < 1 || i > L->length + 1)
  {
    return ERROR;
  }
  if (i <= L->length)
  {
    for (int j = L->length; j >= i; j--)
    {
      L->data[j] = L->data[j - 1];
    }
  }
  L->data[i - 1] = e;
  L->length++;
  return OK;
}

// 删除
Status ListDelete(SqList *L, int i, ElemType *e)
{
  if (L->length < 1 || i > L->length)
  {
    return ERROR;
  }
  *e = L->data[i - 1];
  for (int j = i - 1; j < L->length - 1; j++)
  {
    L->data[j] = L->data[j + 1];
  }
  L->length--;
  return OK;
}

int main()
{
  SqList L;
  L.length = 0;
  ElemType getElem;
  L.data[0] = 0;
  L.data[1] = 1;
  L.data[2] = 2;
  L.length = 3;
  // GetElem(L, 2, &getElem);
  // printf("No.2 is %d\n", getElem);
  // ListInsert(&L, 2, 15);
  printf("%d\n", ListDelete(&L, 3, &getElem));
  print(L);
  printf("%d\n", getElem);
}