/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        // left most item
        int left = 0, right = nums.size() - 1, mid = 0;
        vector<int> res;
        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] == target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }
        if (left >= nums.size())
            res.push_back(-1);
        else if (nums[left] != target)
            res.push_back(-1);
        else
            res.push_back(left);

        // right most target
        left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                left = mid + 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else if (target < nums[mid])
                right = mid - 1;
        }

        if (right < 0)
            res.push_back(-1);
        else if (nums[left-1] != target)
            res.push_back(-1);
        else
            res.push_back(left-1);

        return res;
    }
};
// @lc code=end
