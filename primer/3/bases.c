#include <stdio.h>
int main(void)
{
  int x = 100;
  printf("10: %d, 8: %o, 16: %x\n", x, x, x);
  printf("10: %d, 8: %#o, 16: %#x\n", x, x, x);
}