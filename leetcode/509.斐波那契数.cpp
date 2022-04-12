/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        int a = 0, b = 1, temp = 0;
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else
        {
            while (n>1)
            {
                temp=b;
                b=a+b;
                a=temp;
                n--;
            }
            
        }
        return b;
    }
};
// @lc code=end

