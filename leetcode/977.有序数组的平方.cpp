/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        // find the minimun point
        int i = 0;
        int length = nums.size();
        for (i = 1; i < length - 2; i++)
        {
            if (nums[i - 1] * nums[i - 1] > nums[i] * nums[i] && nums[i] * nums[i] < nums[i + 1] * nums[i + 1])
                i++;
            else
                break;
        }
        if (i == 1)
        {
            if (nums[0] * nums[0] < nums[1] * nums[1])
                i = 0;
        }
        else if (i == length - 2)
        {
            if (nums[length - 2] * nums[length - 2] > nums[length - 1] * nums[length - 1])
                i = length - 1;
        }
        int j = i - 1, k = i + 1;
        vector<int> res;
        res.push_back(nums[i] * nums[i]);
        while (j>=0&&k<length)
        {
            if (nums[j] * nums[j] < nums[k] * nums[k])
            {
                res.push_back(nums[j] * nums[j]);
                j--;
            }
            else
            {
                res.push_back(nums[j] * nums[j]);
                j++;
            }
        }
        while (j >= 0)
        {
            res.push_back(nums[j] * nums[j]);
            j--;
        }
        while (k < length)
        {
            res.push_back(nums[k] * nums[k]);
            k++;
        }

        return res;
    }
};
// @lc code=end
