// 利用指针交换2个变量的值

#include <stdio.h>
void swap(int *i, int *j)
{
    int t;                   // 如果写成int *t,下面写成t =i ;i=j;j=t输出结果还是未发生变化

    t = *i; *i = *j; *j = t; // 交换的是地址还是数值？？？？
    // t=i;i=j;j=t;      //在这返回的是地址还是数值？？？？
}

int main()
{
    int a, b;

    scanf("%d%d", &a, &b);
    swap(&a, &b);
    printf("%d,%d\n", a, b);
    return 0;
}
