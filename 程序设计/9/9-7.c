#include <stdio.h>
#define N 3
struct Student {
  int num;
  char name[20];
  float score[3];
  float aver;
};
int main(void) {
  void input(struct Student stu[]);
  void print(struct Student stu);
  struct Student max(struct Student stu[]);
  struct Student students[3];
  struct Student * p = students;
  // struct Student student[3] * p = students; 上面两句可以简化为一句
  input(p);
  print(max(p));
  return 0;
};

void input(struct Student stu[]) {
  int i;
  printf("请输入个学生的学号、姓名、三门成绩");
  for(i = 0; i < N; i++) {
    scanf("%d %s %f %f %f", &stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
    stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0;
  }
};
struct Student max(struct Student stu[]) {
  int i, m = 0;
  for (i = 0;i < N; i++) {
    if (stu[i].aver > stu[m].aver) {
      m = i;
    }
  }
  return stu[m];
}
void print(struct Student stu) {
  int i;
  printf("打印信息\n");
  printf("学号：%d\n姓名：%s\n平均分：%f\n", stu.num,stu.name,stu.aver);
};
