#include "head.c"

/**
 * 选择排序
 * O(n^2)
 * 不稳定排序
 */
void chooseSort(keytype arr, int n)
{
  int i, j, min, minIndex;
  // 外层循环，寻找第i个最小值
  for (i = 0; i < n; i++)
  {
    min = 123123;
    j = i;
    // 在未排序数字中寻找最小值并记录索引
    while (j < n)
    {
      if (arr[j] < min)
      {
        min = arr[j];
        minIndex = j;
      }
      j++;
    }
    // 将最小值索引与i位置的索引交换
    arr[minIndex] = arr[i];
    arr[i] = min;
  }
}

int main()
{
  keytype arr = {38, 49, 65, 97, 76, 13, 27, 49};
  chooseSort(arr, 8);
  print(arr, 8);
  return 0;
}