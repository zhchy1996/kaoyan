#include <stdio.h>

int main(void)
{
  int a, b;
  int *pointer_1, *pointer_2;
  a = 100;
  b = 10;
  pointer_1 = &a;
  pointer_2 = &b;
  (pointer_1)++;
  printf("%d,%d\n", a, b);                   // 100, 10
  printf("%d,%d\n", *pointer_1, *pointer_2); // 100, 10
  printf("%p,%p\n", pointer_1, pointer_2);   // 0x..... 0x.....
  printf("%d\n", *&a);                       // 100
  return 0;
}