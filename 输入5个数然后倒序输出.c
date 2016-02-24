/*从键盘输入5个数，再将数组从末尾“倒序”打印出来
 */


#include <stdio.h>
int main()
{
    printf("在此输入5个数：\n");
    int i, j = 4, k, a[5];

    for(i = 0; i <= 4; i++)
    {
        printf("a[%d]=", i);     // 循环输出a[0]= ,a[1]= ……，不要这一行代码也可以
        scanf("%d", &a[i]);      // 输入5个数
    }

    for(i = 0; i <= 1; i++, j--) // 做第一个与最后一个，第二个与倒数第二个交换操作。。。循环次数为m=数组里的参数个数/2
    {
        k    = a[i];
        a[i] = a[j];
        a[j] = k;
    }

    for(i = 0; i <= 4; i++) // 循环输出倒序的结果
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
} /* main */
