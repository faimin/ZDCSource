// 利用冒泡排序法输出一组数里最大的那个

#include <stdio.h>
int main()
{
    int a[10], i, j, k;

    for(i = 0; i <= 9; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);     // 循环输入10个数
    }

    for(j = 0; j <= 8; j++)     // 10个数需要重新排列9次
    {
        for(i = 0; i <= 8; i++) // 10个数需要比较互换9次
        {
            if(a[i] > a[i + 1])
            {
                k        = a[i]; // 把比较大的数换到前面去
                a[i]     = a[i + 1];
                a[i + 1] = k;
            }
        }
    }
    printf("数组里最大的数：%d\n", a[i]);   // 输出最大的数
    return 0;
} /* main */
