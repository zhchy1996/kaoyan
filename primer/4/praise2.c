#include <stdio.h>
#include <string.h> //提供strlen()原型
#define PRAISE "what a super marvelous name!"
int main(void)
{
  char name[40];

  printf("what's your name?\n");
  scanf("%s", name);
  printf("hello, %s.%s\n", name, PRAISE);
  printf("your name of %d letters occupies %d memory cells.\n", strlen(name), sizeof(name));
  printf("the phrase of praise has %d letters", strlen(PRAISE));
  printf("and occupies %d memory cells.\n", sizeof PRAISE);
  return 0;
}