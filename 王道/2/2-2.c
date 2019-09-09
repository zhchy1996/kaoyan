#include <stdlib.h>
#include <stdbool.h>
#define InitSize 50 // 表初始长度
typedef int Elemtype;
typedef struct
{
  Elemtype *data;
  int MaxSize,length;
} SqList;
SqList init (SqList);

// 创建
SqList init (SqList L) {
  L.data = (Elemtype*)malloc(sizeof(Elemtype)*InitSize);
  return L;
}

int main(void) {
  SqList L;
  bool a;
  init(L);
  
  return 0;
}

