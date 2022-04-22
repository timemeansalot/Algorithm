/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */
#include "headfile.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast)
        {
            if (fast->val != slow->val)
            {
                slow->next = fast;
                slow = slow->next;
            }
            if (fast->next)
                fast = fast->next;
            else
                break;
        }

        // [1,1,2,3,3]中，保留后面一个3
        // if (slow && fast)
        //     if (slow->val == fast->val)
        //         slow->next = nullptr;
        slow->next = nullptr;
        return head;
    }
};
// @lc code=end
