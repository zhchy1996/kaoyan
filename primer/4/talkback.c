#include <stdio.h>
#include <string.h>  // 提供strlen()函数的原型
#define DENSITY 62.4 // 人的密度（单位：英镑/每立方尺)
int main(void)
{
  float weight, volume;
  int size, letters;
  char name[40]; //name是一个有40个字符的数组

  printf("hi! what's your first name?\n");
  scanf("%s", name);
  printf("%s, what's your weight?\n", name);
  scanf("%f", &weight);
  size = sizeof name;
  letters = strlen(name);
  volume = weight / DENSITY;
  printf("%s, your volume is %2.2f cubic feet.\n", name, volume);
  printf("your first name has %d letters\n", letters);
  printf("we have %d bytes to store it\n", size);
  return 0;
}
