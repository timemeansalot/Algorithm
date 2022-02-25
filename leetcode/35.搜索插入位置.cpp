/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size();
        int m = (l + m) / 2;
        while (l < r)
        {
            m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        if (nums[m] < target)
            return m + 1;
        return m;
    }
};
// @lc code=end
