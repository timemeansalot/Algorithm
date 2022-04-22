/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return 1;

        // nums has at least 2 items
        int slow = 0, fast = 1;

        while (fast < nums.size())
        {
            if (nums[fast] == nums[slow])
            {
                fast++;
            }
            else
            {
                slow++;
                nums[slow] = nums[fast];
                fast++;
            }
        }
        return slow + 1;
    }
};
// @lc code=end
