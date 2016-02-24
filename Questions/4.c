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
        struct student *p;      // 定义一个结构体指针变量p
        p = &stu[i];            // p指向第i个学生信息的首地址
        printf("姓名：\n");
        scanf("%s", p->name);
        printf("学号：\n");
        scanf("%s", p->idnumber);
        printf("成绩：\n");
        scanf( "%f", &(p->score) );
        p++;               // 输入完一个学生的信息后，指针后移一位，指到后面第二个学生
    }
    compare(stu, len);     // 调用函数比较两个学生的成绩
    return 0;
} /* main */

// 定义一个比较学生成绩的函数
void compare(struct student stu[], float len)
{
    float           max = 0;  // 定义一个第三方数值与学生分数作比较
    struct student *s;        // 定义一个结构体指针变量

    for(int i = 0; i < 2; i++)
    {
        float score = stu[i].score;

        if(score > max)
        {
            max = score;
            s   = &stu[i];           // 输出分数较高的学生地址
        }
    }

    printf("姓名：%s,学号：%s,成绩：%.2f\n", s->name, s->idnumber, s->score);
} /* compare */
