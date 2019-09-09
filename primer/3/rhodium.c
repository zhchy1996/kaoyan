#include <stdio.h>
int main(void)
{
  float weight;
  float value;
  printf("输入你的体重:");
  scanf("%f", &weight);
  value = 770 * weight * 14.5833;
  printf("你的体重换算成铑价值$%.2f\n", value);
  return 0;
}