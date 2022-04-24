#include "headfile.h"

int binary_search(vector<int> nums, int target)
{
    int left = 0, right = nums.size() - 1; // 区间左闭右闭
    int mid = 0;

    while (left <= right) // 区间左闭右闭，所以left=right的时候，代表区间内还有一个元素
    {
        mid = left + (right - left) / 2; // 避免left+right溢出

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else if (target < nums[mid])
            right = mid - 1;
    }

    return -1;
}

int main()
{
}

//-214748364
//-2147483648
