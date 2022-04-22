/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include "headfile.h"
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> res;
        int left =0,right=numbers.size()-1; // 相向指针
        int sum=0;
        while (left<right)
        {
            sum=numbers[left]+numbers[right];
            if(sum==target)
            {
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            if(sum<target)
            {
                left++; // make sum bigger, becuase sum < target
            }
            else
            {
                right--; // make sum smaller, because sum > target
            }
        }
        
        return res;
    }
};
// @lc code=end
