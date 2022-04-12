/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include "headfile.h"
// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        int *dp = new int[amount + 1]();
        int result = INT32_MAX;
        dp[0] = 0; // when target amount is 0, need 0 coins to match amount
        for (; amount > 0;)
        {
            for (auto coin : coins)
            {
                if (amount > coin)
                {
                    result = min(result, 1 + dp[amount - coin]);
                    amount -= coin;
                }
            }
        }
        return result;
    }
};
// @lc code=end
