#include <stdio.h>
int main(void)
{
  char ch;
  printf("please enter a character\n");
  scanf("%c", &ch);
  printf("code is %c is %d.\n", ch, ch);
  return 0;
}