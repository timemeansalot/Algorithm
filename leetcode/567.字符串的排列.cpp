/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        unordered_map<char, int> need, windows;
        int left = 0, right = 0, total = 0, start = 0, len = INT32_MAX;
        char c, d;

        for (auto char_s1 : s1)
        {
            need[char_s1] += 1;
        }

        while (right < s2.size())
        {
            d = s2[right];
            right++;

            // fi d is not the char in s1, then drop current windows because it will be pulluted by d
            if (need.count(d) == 0)
            {
                windows.clear();
                left = right;
                total = 0;
                continue;
            }

            if (need.count(d))
            {
                // put d into windows
                windows[d]++;
                if (windows[d] == need[d])
                    total++;
            }

            while (total == need.size())
            {
                // store crruent windows info
                if (right - left < len)
                {
                    start = left;
                    len = right - left;

                    if (len == s1.size())
                        return true;
                }

                c = s2[left];
                left++;
                if (need[c])
                {
                    if (windows[c] == need[c])
                        total--;
                    windows[c]--;
                }
            }
        }
        // if (total == need.size() - 1)
        //     if (right - left == s1.size())
        //         return true;

        return false;
    }
};
// @lc code=end
