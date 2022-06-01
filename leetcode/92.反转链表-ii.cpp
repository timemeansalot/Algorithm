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
        ListNode *p = new ListNode;
        ListNode *first = head, *l = head, *r = head;
        bool flag = false;
        int count = 0;
        p->next = head;

        while (count < right && r != nullptr)
        {
            count += 1;
            l = r;
            r = r->next;

            if (count == left - 1)
            {
                p = l;
                flag = true;
            }
            if (count == left)
            {
                first = l;
            }

            if (count >= left && count <= right)
            {
                l->next = p->next;
                p->next = l;
            }
        }
        first->next = r;

        if (flag == false)
            return p->next;
        else
            return head;
    }
};
// @lc code=end
