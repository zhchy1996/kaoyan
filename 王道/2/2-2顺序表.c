#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define InitSize 50 // 表初始长度
typedef int Elemtype;
// 表结构
typedef struct
{
  Elemtype *data;
  int MaxSize, length;
} SqList;
// 方法声明
SqList init(SqList *);
void print(SqList);
bool ListInsert(SqList *L, int i, Elemtype);
bool ListDelect(SqList *L, int i, Elemtype *e);
int LocateElem(SqList *L, Elemtype e);

// 初始化
SqList init(SqList *L)
{
  L->data = (Elemtype *)malloc(sizeof(Elemtype) * InitSize);
  L->length = 0;
  return *L;
}

// 打印
void print(SqList L)
{
  for (int i = 0; i < L.length; i++)
  {
    printf("data is: %5d\n", L.data[i]);
  }
  printf("length is: %d\n", L.length);
}

// 插入
bool ListInsert(SqList *L, int i, Elemtype e)
{
  if (i < 1 || i > L->length + 1)
  {
    printf("插入失败：超出范围\n");
    return false;
  }
  for (int j = L->length; j >= i; j--)
  {
    L->data[j] = L->data[j - 1];
  }
  L->data[i - 1] = e;
  L->length++;
  return true;
}

// 删除
bool ListDelect(SqList *L, int i, Elemtype *e)
{
  if (i < 1 || i > L->length)
  {
    printf("删除失败：超出范围");
    return false;
  }
  *e = L->data[i - 1];
  L->length--;
  for (int j = i - 1; j < L->length; j++)
  {
    L->data[j] = L->data[j + 1];
  }
  return true;
}

// 查找
int LocateElem(SqList *L, Elemtype e)
{
  for (int i = 0; i < L->length; i++)
  {
    if (L->data[i] == e)
    {
      return i + 1;
    }
  }
  return 0;
}

int main(void)
{
  SqList L;
  init(&L);
  Elemtype delE;
  // 添加测试
  for (int i = 0; i < 10; i++)
  {
    ListInsert(&L, i + 1, i);
  }
  // print(L);

  // 删除测试
  ListDelect(&L, 2, &delE);
  // print(L);
  // printf("del Element is %d\n", delE);

  // 查找测试
  printf("i find the elem's position is %d\n", LocateElem(&L, 4));

  return 0;
}
