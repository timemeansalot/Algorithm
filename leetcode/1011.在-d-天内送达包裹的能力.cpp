/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = 0, right = 0, mid = 0;
        // 船 最小运送能力是所有包裹的最大值，最大运送能力是所有包裹的总和
        for (int w : weights)
        {
            if (left < w)
                left = w;
            right += w;
        }

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (totalTransferDays(weights, mid) <= days)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

    int totalTransferDays(vector<int> &weights, int capacity)
    {
        // 至少需要运输一天，初始的空余容量是船的总capacity
        int days = 1, remain_space = capacity;
        for (int w : weights)
        {
            if (w <= remain_space)
            {
                remain_space -= w;
                continue;
            }
            else
            {
                remain_space = capacity - w;
                days++;
            }
        }
        return days;
    }
};
// @lc code=end
