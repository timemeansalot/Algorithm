/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        queue<int> q;
        int sign = x >= 0 ? 1 : -1;
        int res = 0;
        bool valid = false;

        // x *= sign;
        while (x)
        {
            q.push(x % 10);
            x /= 10;
        }

        while (q.size())
        {
            if (~valid)
                if (q.front())
                    valid = true;

            if (valid == false)
            {
                q.pop();
            }
            else
            {
                if (res >= INT32_MAX / 10)
                {
                    if (res > INT32_MAX / 10)
                        return 0;
                    else if (res == INT32_MAX / 10 && q.front()>7)
                        return 0;
                }
                if(res<=INT32_MIN/10)
                {
                    if(res<INT32_MIN/10)
                    return 0;
                    else if(res==INT32_MIN/10&&q.front()<-4)
                    return 0;
                }
                res = res * 10 + q.front();
                q.pop();
            }
        }
        // res *= sign;
        return res;
    }
};
// @lc code=end
