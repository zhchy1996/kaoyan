#include <stdio.h>
#include <string.h>
int main(void)
{
  struct Student
  {
    int num;
    char name[20];
    char sex;
    int age;
  };
  struct Student stu[3]={{}}
  struct Student student1;
  struct Student * p;
  p = &student1;
  student1.num = 10101w;
  strcpy(student1.name, "Li Lin");
  strcpy(student1.addr, "BeiJing");
  printf("num:%ld\nname:%s\nsex:%c\naddr:%s\n", p->num, (*p).name, (*p).sex, (*p).addr);
  return 0;
}