#include "head.c"

/**
 * 插入排序
 * 时间复杂度:O(n^2)
 * 辅助空间:1  tmp
 * 稳定排序
 */
void sort(keytype arr, int n)
{
  int i, j, tmp;
  // 从第二位向后遍历
  for (i = 1; i < n; i++)
  {
    tmp = arr[i];
    j = i - 1;
    // 当遇到比tmp大的项时将其后移
    while (j >= 0 && tmp < arr[j])
    {
      arr[j + 1] = arr[j];
      j--;
    }
    // 遇到比tmp小的项时将tmp插入到其后面
    arr[j + 1] = tmp;
  }
}

/**
 * 折半插入
 */
void halfSort(keytype arr, int n)
{
  int i, j, tmp, low, high, mid;
  for (i = 1; i < n; i++)
  {
    tmp = arr[i];
    low = 0;
    high = i - 1;
    while (low <= high)
    {
      // 查找到tmp应该插入的位置
      mid = (low + high) / 2;
      if (tmp < arr[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    // low即为应该插入的位置，将low之后（包括low）的元素向后移
    for (j = i - 1; j >= low; j--)
    {
      arr[j + 1] = arr[j];
    }
    // 给low赋值
    arr[low] = tmp;
    print(arr, 8);
  }
}

int main()
{
  keytype arr = {38, 49, 65, 97, 76, 13, 27, 49};
  // sort(arr, 8);
  halfSort(arr, 8);
  print(arr, 8);
  return 0;
}