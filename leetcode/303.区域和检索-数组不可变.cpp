/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include "header.h"
// @lc code=start
class NumArray
{
    int pre_sum[10001];

public:
    NumArray(vector<int> &nums)
    {
        // constructor
        // for arrays nums: pre_sum[k]=nums[0]+...+nums[k-1] 
        // eg: pre_sum[0]=0, pre_sum[1]=nums[0]
        //     pre_sum[2]=num[0]+nums[1]
        pre_sum[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pre_sum[i+1] = nums[i] + pre_sum[i];
        }
    }

    int sumRange(int left, int right)
    {
        return pre_sum[right+1] - pre_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
