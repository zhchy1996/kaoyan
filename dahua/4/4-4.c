#include "head.c"
int Fbi(int n)
{
  if (n < 2)
    return n == 0 ? 0 : 1;
  return Fbi(n - 1) + Fbi(n - 2);
}

int main()
{
  printf("%d\n", Fbi(5));
  return 0;
}