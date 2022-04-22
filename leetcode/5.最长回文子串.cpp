/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            string res1 = findPalindrome(s, i, i);
            string res2 = findPalindrome(s, i, i + 1);

            res = res.length() < res1.length() ? res1 : res;
            res = res.length() < res2.length() ? res2 : res;
        }
        return res;
    }
    string findPalindrome(string s, int left, int right)
    {
        while ((0 <= left && right < s.size()) && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right-left-1); // substr(pos,length)
    }
};
// @lc code=end
