/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        int count = 1;
        ListNode *p = head, *lp = head, *rp = head;
        ListNode *first = head;

        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        if (left == right)
            return head;

        while (count < left - 1)
        {
            p = p->next;
        }

        count = 0;
        while (count <= right)
        {
            if (count == left)
                first = lp;
            if (count >= left)
            {
                lp->next = p->next;
                p->next = lp;
            }

            lp = rp;
            rp = rp->next;
            count += 1;
        }
        first->next = lp;

        return head;
    }
};
// @lc code=end
