#include "display.h"

template <typename T>
int partition(T a[],  int low,  int high)
{
    int target = a[low];
    while (low < high)
    {
        while (low < high && target <= a[high])
            high--;
        a[low] = a[high]; // 将比基准元素小的元素交换到左边
        while (low < high && a[low] <= target)
            low++;
        a[high] = a[low]; // 将比基准元素大的元素交换到右边
    }
    a[low] = target; // 将基准元素放到两部分中间
    return low;      // 返回分段的index
}

template <typename T>
void quick_sort(T a[], const int low, const int high)
{
    if (low >= high) // 如果只有一个元素了，返回
        return;

    int index = partition(a, low, high);
    quick_sort(a, low, index - 1);
    quick_sort(a, index + 1, high);
}

int main()
{
    int length = 8;
    int a[] = {4, 2, 3, 1, 7, 1, 9, 2};

    display_array(a, length);
    quick_sort(a, 0, length - 1);
    display_array(a, length);
    cout << "hello quick sort" << endl;
}