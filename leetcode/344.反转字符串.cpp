/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include "headfile.h"
// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s)
    {

        // 使用相向指针即可
        int left = 0, right = s.size() - 1;
        char temp;
        while (left<right)
        {
            temp=s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
        }
        
    }
};
// @lc code=end
