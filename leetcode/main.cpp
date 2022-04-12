#include "headfile.h"

class Solution
{
public:
    int fib(int n)
    {
        int *memo = new int[32]();
        int result = 0;
        result = helper(memo, n);
        delete[] memo;
        return result;
    }
    int helper(int memo[], int n)
    {
        if (n == 0 || n == 1)
            return n;
        if (memo[n] != 0)
            return memo[n];
        // 递归，但是由于使用了备忘录，大大减小了计算量
        return helper(memo, n - 1) + helper(memo, n - 2);
        return memo[n];
    }
};
int main()
{
    Solution s;
    cout << s.fib(31) << endl;
}