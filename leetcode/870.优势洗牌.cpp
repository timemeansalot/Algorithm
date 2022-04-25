/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

#include "headfile.h"
// @lc code=start
class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int left = 0, right = nums1.size() - 1;
        priority_queue<pair<int, int>> pq;
        vector<int> res(nums1.size());

        for (int i = 0; i < nums2.size(); i++)
            pq.push(make_pair(nums2[i], i));

        sort(nums1.begin(), nums1.end(), greater<int>());

        while (left <= right)
        {
            if (nums1[left] > pq.top().first)
            {
                res[pq.top().second] = nums1[left];
                left++;
                pq.pop();
            }
            else
            {
                res[pq.top().second] = nums1[right];
                right--;
                pq.pop();
            }
        }
        return res;
    }
};
// @lc code=end
