// 结构体

/*
 *  定义一个学生的结构体，成员变量有名字、学籍号、某一学科的成绩。
 *  分别从键盘读入两个学生的信息。最后再后台输出谁的成绩好就在公告栏里表彰出来，
 *  如果成绩相同，那么就在公告栏中一同显示出来。
 */
#include <stdio.h>
struct student
{
    char  name[20];
    char  idnumber[30];
    float score;
};

void compare(struct student stu[], float len);       // 声明后面要调用的函数
int main()
{
    struct student stu[2];                           // 定义一个结构体数组

    long len = sizeof(stu) / sizeof(struct student); // 数组长度

    // 输入两个学生的姓名、学号、成绩
    for(int i = 0; i < len; i++)
    {
        /*
         *  struct student *p;
         *  p=&stu;
         */
        printf("姓名：\n");
        scanf("%s", stu[i].name);
        printf("学号：\n");
        scanf("%s", stu[i].idnumber);
        printf("成绩：\n");
        scanf("%f", &stu[i].score);
        // p++;
    }
    compare(stu, len);
    return 0;
} /* main */

void compare(struct student stu[], float len)
{
    // struct student stu[2];
    float max = 0;

    // struct student *s;
    // s	=&stu;

    for(int i = 0; i < 2; i++)
    {
        float score = stu[i].score;

        if(score > max)
        {
            max = score;
        }
    }
    printf("最好成绩：%.2f\n", max);
} /* compare */
