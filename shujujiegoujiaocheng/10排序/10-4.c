#include "head.c"

/**
 * 冒泡排序
 */
void popSort(keytype arr, int n)
{
  int i, j, tmp, flag;
  flag = 1;
  for (i = n - 1; i >= 0; i--)
  {
    if (flag == 0)
    {
      return;
    }
    j = 0;
    flag = 0;
    while (j < i)
    {
      if (arr[j] > arr[j + 1])
      {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
        flag = 1;
      }
      j++;
    }
  }
}

int main()
{
  keytype arr = {38, 49, 65, 97, 76, 13, 27, 49};
  popSort(arr, 8);
  print(arr, 8);
  return 0;
}