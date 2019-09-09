#include <stdio.h>

int main(void)
{
  printf("size is %zd\n", sizeof(int));
  printf("size is %lu\n", sizeof(char));
  printf("size is %u\n", sizeof(long));
  printf("size is %u\n", sizeof(double));
  return 0;
}