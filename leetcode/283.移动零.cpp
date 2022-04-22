/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include "headfile.h"
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0,fast=0;

        while (fast<nums.size())
        {
            if(nums[fast]!=0)
            {
                nums[slow]=nums[fast];
                slow++;
            }
            fast++;
        }
        while (slow<nums.size())
        {
            nums[slow]=0;
            slow++;
        }
        
        
    }
};
// @lc code=end

