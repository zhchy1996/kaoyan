#include <stdio.h>
int main(void)
{
  struct Student
  {
    int num;
    char name[10];
    float score;
  } student1, student2;

  scanf("%d%s%f", &student1.num, student1.name, &student1.score);
  scanf("%d%s%f", &student2.num, student2.name, &student2.score);
  if (student1.score > student2.score) {
    printf("%d %s %5f", student1.num, student1.name, student1.score);
  } else if (student1.score < student2.score) {
    printf("%d %s %5f", student2.num, student2.name, student2.score);
  } else {
    printf("%d %s %5f", student1.num, student1.name, student1.score);
    printf("%d %s %5f", student2.num, student2.name, student2.score);
  }
  return 0;
}