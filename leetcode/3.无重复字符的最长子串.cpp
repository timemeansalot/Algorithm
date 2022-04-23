/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        unordered_map<char, int> windows;

        int left = 0, right = 0, start = 0, len = 0;
        int more_than_once = 0;
        char c, d;
        while (right < s.size())
        {
            d = s[right];
            right++;

            // put into windows
            windows[d]++;
            if (windows[d] == 2)
                more_than_once++;

            while (more_than_once > 0)
            {

                c = s[left];
                left++;

                if (windows[c] == 2)
                    more_than_once--;
                windows[c]--;
            }

            if (len < right - left)
            {
                len = right - left;
            }
        }
        return len;
    }
};
// @lc code=end
