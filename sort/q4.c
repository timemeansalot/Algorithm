#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int n, int t[], int number[])
{ 
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (t[j] < t[j + 1])
            {
                int tt = 0;
                tt = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tt;

                int n = 0;
                n = number[j];
                number[j] = number[j + 1];
                number[j + 1] = n;
            }
        }
    }
}

int main()
{
    int n;                 
    int t[100] = {0};      
    int number[100] = {0}; 
    int MinTime1 = 0;      
    int MinTime2 = 0;      
    int MinTime3 = 0;      
    int status[100] = {0}; 

    printf("输入待加工的任务总数:");
    scanf("%d", &n);
    printf("\n");

    printf("分别输入每项任务的加工时间:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t[i]);
        number[i] = i + 1;
    }
    printf("\n");

    printf("任务编号     任务加工时间\n");
    for (int i = 0; i < n; i++)
    {
        printf("%5d         %5d\n", number[i], t[i]);
    }
    printf("\n");

    bubble_sort(n, t, number); //任务的编号要随着任务加工时间的交换而交换

    // change
    if (n <= 3)
    {
        MinTime1 = t[0]; //任务总数不超过机器数（这里机器总数为2）时,最短总加工时间一定是下标为0的任务的加工时间，且此时该任务一定由第一台机器加工
        status[0] = 1;   //标记为第一台机器加工
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (MinTime1 <= MinTime2 && MinTime1 <= MinTime3)
            { // change//由第一台机器加工，注意这里的判断条件一定是小于等于而不是小于，否则会出现错误
                MinTime1 = MinTime1 + t[i];
                status[i] = 1; //标记为第一台机器加工
            }
            else if (MinTime2 <= MinTime3)
            { //由第二台机器加工
                MinTime2 = MinTime2 + t[i];
            }
            else
            {
                MinTime3 += t[i];
            }

            printf("i= %d, t1= %d, t2= %d, t3= %d\n", i, MinTime1, MinTime2, MinTime3);
        }
    }

    if (MinTime1 >= MinTime2 && MinTime1 >= MinTime3)
    {
        return MinTime1;
    }
    else if (MinTime2 >= MinTime3)
    {
        return MinTime2;
    }
    else
    {
        return MinTime3;
    }

    return 0;
}
