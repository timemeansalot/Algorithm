/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {

        unordered_map<char, int> need, window;

        int left = 0, right = 0, total = 0, start = 0, len = INT32_MAX;
        char d, c;
        for (auto i : t)
        {
            need[i] += 1; // 记录目标字符串中，各种字符需要的次数
        }

        while (right < s.size())
        {
            d = s[right];
            right++;

            // 从右边扩大窗口
            if (need.count(d)) // 如果字符d在目标字符串中
            {
                window[d]++;              // 在Windows中将字符串d出现的次数+1
                if (window[d] == need[d]) // 如果Windows中d出现的次数等于need中d出现的次数
                {
                    total++;
                }
            }

            // 看看是不是需要从左边缩小窗口
            while (total == need.size()) // need中所有字符串出现的次数都满足要求
            {
                // 更新start,len: 保存窗口当前的信息
                if (right - left  < len)
                {
                    len = right - left;
                    start = left;
                }

                // 缩小窗口
                c = s[left];
                left++;
                if (need.count(c)) // 如果字符c在need中有
                {
                    if (window[c] == need[c]) // 在不删除c之前，need和window中c的数量是吻合的
                    {
                        total--;
                    }
                    window[c]--;
                }
            }
        }

        if (len <= s.size())
        {
            return s.substr(start, len);
        }
        return "";
    }
};
// @lc code=end
