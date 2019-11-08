#include "head.c"

/**
 * 希尔排序
 * 时间复杂度在O(nlog2n)~O(n^2)之间
 * 不稳定的排序算法
 */
void shellSort(keytype arr, int n)
{
  int i, j, tmp, gap, flag;
  gap = n;
  while (gap > 1)
  {
    // 初始取gap为n/2，每轮后缩小间隔
    gap = gap / 2;
    // 使用冒泡排序对子序列排序
    do
    {
      flag = 0;
      // 将最大值移动到子序列右侧
      for (i = 0; i < n - gap; i++)
      {
        if (arr[i] > arr[i + gap])
        {
          tmp = arr[i];
          arr[i] = arr[i + gap];
          arr[i + gap] = tmp;
          flag = 1;
        }
      }
    } while (flag != 0);
  }
}

int main()
{
  keytype arr = {38, 49, 65, 97, 76, 13, 27, 49};
  shellSort(arr, 8);
  print(arr, 8);
  return 0;
}