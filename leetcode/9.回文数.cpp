/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        else if (x == 0)
        {
            return true;
        }

        int temp = x;
        int length = 0;
        while (temp > 0)
        {
            length++;
            temp /= 10;
        }

        temp = x;
        stack<int> s;

        for (int i = 0; i < length / 2; i++)
        {
            s.push(temp % 10);
            temp /= 10;
        }
        if (length % 2 == 1)
        {
            temp /= 10;
        }
        while (temp > 0)
        {
            if (temp % 10 == s.top())
            {
                s.pop();
                temp /= 10;
            }
            else
                return false;
        }
        if (s.empty())
            return true;

        return 0;
    }
};
// @lc code=end
 