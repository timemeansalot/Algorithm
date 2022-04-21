/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include "headfile.h"
// @lc code=start
class NumArray
{
private:
    int pre_sum[10001];

public:
    NumArray(vector<int> &nums)
    {
        pre_sum[0] = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            // pre_sum[0]=0, 表示此时还没有元素
            // pre_sum[1]=nums[0]
            pre_sum[i + 1] = pre_sum[i] + nums[i]; // 计算前缀和，通过前缀和可以在O(1)内算出区间和
        }
    }

    int sumRange(int left, int right)
    {
        return pre_sum[right + 1] - pre_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
