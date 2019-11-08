#include <stdio.h>

typedef int keytype[];

void print(keytype arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%4d", arr[i]);
  }
  printf("\n");
}
