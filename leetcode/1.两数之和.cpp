/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m[target - nums[i]])
            {
                ans[0] = target - nums[i];
                ans[1] = nums[i];
                return ans;
            }
            else
            {
                m[nums[i]]=1;
            }
        }
        ans.push_back(-1);   
        ans.push_back(-1);   
        return ans;
    }
};
// @lc code=end
