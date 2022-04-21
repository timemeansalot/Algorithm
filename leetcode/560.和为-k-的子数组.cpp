/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

#include "headfile.h"

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0, pre_sum = 0;
        unordered_map<int, int> map; // <前缀和的值，出现的次数>

        map[0] = 1; // 一开始前缀和是0，所以前缀和为0出现的次数初始化为1
        for (auto num:nums)
        {
            pre_sum+=num;

            if(map.count(pre_sum-k)) // 比当前pre_sum小k的pre_sum存在， map.count(key)只返回0，1
            {
                count+=map[pre_sum-k]; // map[pre_sum-k]返回比当前的pre_sum小k的pre_sum的个数
            }

            map[pre_sum]++; // 将当前的pre_sum放到map中
        }
        return count;
    }
};
// @lc code=end
