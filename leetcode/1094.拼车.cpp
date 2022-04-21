/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {

        vector<int> diff(1001);
        vector<int> nums(1001);

        
        // 构造diff数组
        for (int i = 0; i < trips.size(); i++)
        {
            if (trips[i][1] - 1 >= 0)
                diff[trips[i][1] - 1] -= trips[i][0];
            else
                diff[0] -= trips[i][0];

            if (trips[i][2] < diff.size())
                diff[trips[i][2]-1] += trips[i][0];

            // // print diff
            // for (auto d : diff)
            //     cout << d << " ";
            // cout << endl;
        }

        // 计算nums数组
        nums[0] = capacity+diff[0];
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = diff[i] + nums[i - 1];
            if (nums[i] < 0)
                    return false;
        }
        return true;
    }
};
// @lc code=end
