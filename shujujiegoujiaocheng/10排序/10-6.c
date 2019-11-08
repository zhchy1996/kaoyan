#include "head.c"
void swap(int *i, int *j);

void quickSort(keytype arr, int s, int t)
{
  int i, j;
  if (s < t)
  {
    i = s;
    j = t + 1;
    while (1)
    {
      do
        i++;
      while (!(arr[s] <= arr[i] || i == t));
      do
        j--;
      while (!(arr[s] >= arr[j] || j == s));
      if (i < j)
        swap(&arr[i], &arr[j]);
      else
        break;
    }
    swap(&arr[s], &arr[j]);
    quickSort(arr, s, j - 1);
    quickSort(arr, j + 1, t);
  }
}

void swap(int *i, int *j)
{
  int tmp;
  tmp = *i;
  *i = *j;
  *j = tmp;
}

int main()
{
  keytype arr = {49, 38, 65, 97, 76, 13, 27, 49};
  quickSort(arr, 0, 7);
  print(arr, 8);
  return 0;
}