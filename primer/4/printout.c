#include <stdio.h>
#define PI 3.141593

int main(void)
{
  int number = 5;
  float expresso = 13.5;
  int cost = 3100;
  printf("the %4d ceos drank %f cups of expresso.\n", number, expresso);
  printf("the value of pi is %f\n", PI);
  printf("farewell! thou art too dear for my possessing, \n");
  printf("%c%d\n", '$', 2 * cost);
}