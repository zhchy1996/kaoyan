#include <stdio.h>
#define NUM 5;
int avgAge(int a[]);

int main()
{
  int arr[] = {22, 33, 24, 45, 12};
  printf("len=%d, a=%d\n", sizeof(arr) / sizeof(arr[0]), sizeof(arr));
  return avgAge(arr);
}

int avgAge(int a[])
{
  // 判断是不是空数组。
  // int arr[] = {22, 33, 24, 45, 12};
  int sum;
  int len = sizeof(a) / sizeof(a[0]);
  printf("%d\n", a[2]);
  printf("len=%d, a=%d\n", len, sizeof(a));
  for (int i = 0; i < len; i++)
  {
    sum += i;
  }
  return sum / len;
}