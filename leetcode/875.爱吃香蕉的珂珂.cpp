/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

#include "headfile.h"
// @lc code=start
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1, right = 0, mid = 0; // 最小是吃香蕉速度是1，最大的吃香蕉速度是piles中的最大值

        for (int p : piles)
            if (p > right)
                right = p;

        // 寻找最小的速度：可以满足在时间h内，吃完所有piles中的香蕉
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (totalTime(piles, mid) <= h)
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

    // 确定速度之后，吃完所有香蕉需要的时间
    int totalTime(vector<int> &piles, int speed)
    {
        int sum = 0;
        for (int p : piles)
        {
            sum += p / speed;
            if (p % speed)
                sum++; // 向上取整
        }
        return sum;
    }
};
// @lc code=end
