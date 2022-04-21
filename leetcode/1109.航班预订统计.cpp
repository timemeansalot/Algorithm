/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

#include "headfile.h"
// @lc code=start
class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {

        vector<int> diff(n); // 差分数组
        vector<int> nums(n);
        // 计算差分数组
        for (int i = 0; i < bookings.size(); i++)
        {
            diff[bookings[i][0] - 1] += bookings[i][2];
            if (bookings[i][1] < nums.size()) // 如果结尾大于diff数组的长度,则所有后面的都要改
                diff[bookings[i][1]] -= bookings[i][2];
        }

        // 由差分数组计算nums数组
        nums[0] = diff[0];
        for (int i = 1; i < n; i++)
        {
            nums[i] = nums[i - 1] + diff[i];
        }

        return nums;
    }
};
// @lc code=end
