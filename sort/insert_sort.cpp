#include <iostream>
#include "display.h"
using namespace std;

/**
 * @brief 在有序序列中搜索目标元素，返回不大于目标元素的最大下标。如在[1,3,5,7]中搜索4，则返回1
 *
 * @tparam T 模板类型
 * @param a 有序的数组
 * @param target 需要搜索的目标
 * @param length 数组的长度
 * @return int 不大于目标元素的最大下标
 */
template <typename T>
int binary_search(T a[], const int target, const int length)
{
    int left = 0, right = length - 1;
    int m = 0;
    while (left < right)
    {
        m = (left + right) >> 1;
        if (a[m] == target)
            return m;
        else if (a[m] < target)
        {
            left = m + 1;
        }
        else
        {
            right = m - 1;
        }
    }

    return left;
}

/**
 * @brief do insert sort
 *
 * @tparam T Template typename
 * @param a array which will need sort
 * @param length array length
 * @return int return 1 after sort
 */
template <typename T>
int insert_sort(T a[], const int length)
{
    int temp = 0;
    int index = 0;

    for (int i = 1; i < length; i++)
    {
        index = binary_search(a, a[i], i);
        temp = a[i];
        for (int j = i; j > index + 1; j--)
        {
            a[j] = a[j - 1];
        }
        a[index] = temp;
    }
    return 1;
}

int main()
{
    // while (1)
    // {

    // }
    int length = 5;
    int target = 0;
    // int *a = new int[length];
    int a[] = {4, 2, 3, 1, 7};

    // cout << "input length: ";
    // cin >> length;
    // cout << endl
    //      << "input target: ";
    // cin >> target;
    // cout << endl
    //      << "input a: ";
    // for (int i = 0; i < length; i++)
    //     cin >> a[i];
    display_array(a, length);
    insert_sort(a, length);
    display_array(a, length);
    return 0;
}