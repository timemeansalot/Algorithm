/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int res = 0, count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                res = nums[i];
            }
            if (res == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return res;
    }
};
// @lc code=end
