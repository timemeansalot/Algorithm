/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include "headfile.h"
// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {

        vector<int> res;
        unordered_map<char, int> need, windows;
        int left = 0, right = 0, total = 0, start = 0, len = INT32_MAX;
        char c, d;

        for (auto c : p)
            need[c]++;

        while (right < s.size())
        {
            d = s[right];
            right++;

            // if d in needed
            if (need.count(d))
            {
                windows[d]++;
                if (windows[d] == need[d])
                    total++;
            }

            while (right - left >= p.size()) // the windows size is fixed to p.size()
            {
                if (total==need.size())
                {
                    res.push_back(left);
                }

                c = s[left];
                left++;

                if (need.count(c))
                {
                    if (windows[c] == need[c])
                        total--;
                    windows[c]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
