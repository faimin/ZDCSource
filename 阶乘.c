// 如果不注释掉自定义函数中的printf的话输出结果
// 为1-n的所有n！的值。。。。why？？？

#include <stdio.h>
int g(int m)         // 自定义阶乘函数
{
    int n;

    if(m == 1)          // 1的阶乘
    {
        n = 1;
    }
    else if(m > 1)         // m的阶乘
    {
        n = m * g(m - 1);
    }
    // printf("%d\n",n);   //为什么运行结果会输出1--n的
    return n;     // 所有阶乘的结果？？？？？
} /* g */

int main()        // 主函数
{
    int i, j;

    printf("阶乘：");
    scanf("%d", &i);      // 输入一个数
    j = g(i);             // 调用g函数
    printf("%d!=%d\n", i, j);
    return 0;
}
