#include <stdio.h>
int main(void)
{
  int feet, fathoms;
  fathoms = 2;
  feet = 6 * fathoms;
  printf("there are %d in %d fathoms\n", feet, fathoms);
  printf("%d feet\n", 6 * fathoms);
}