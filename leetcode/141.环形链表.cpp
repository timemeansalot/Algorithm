/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
#include "headfile.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // if head is null, return false
        if (head == nullptr)
            return false;
        // use empty node to handle the situation that there is only one node in head.
        ListNode *slow = new ListNode;
        slow->next = head;
        ListNode *fast = slow;
        while (fast)
        {
            if (fast)
                fast = fast->next;
            if (fast)
                fast = fast->next;

            slow = slow->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};
// @lc code=end
