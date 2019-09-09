#include <stdio.h>
void butler(void);
int main(void)
{
  printf("准备调用butler\n");
  butler();
  printf("调用结束\n");
}
void butler(void)
{
  printf("调用butler\n");
}