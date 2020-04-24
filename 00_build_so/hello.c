#include <stdio.h>

void Sort(int a[], int len)
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
    {
        for (j = len - 1; j > i; j--)
            if (a[j] < a[j - 1])
            {
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
    }
}

int main()
{
    int nNumbers[10];
    for (int i = 0; i < 10; i++)
    {
        printf("请输入第%2d个数：", i + 1);
        scanf("%d", &nNumbers[i]);
    }
    printf("\n\n您输入的数字为：\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", nNumbers[i]);
    }

    Sort(nNumbers, 10);
    printf("\n\n排序后的结果为：\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", nNumbers[i]);
    }
    printf("\n");
    return 0;
}