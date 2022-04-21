/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        if (headA == nullptr || headB == nullptr)
            return nullptr;

        int a_length = 0, b_length = 0, length_diff = 0;
        ListNode *inter = headA;

        a_length = list_length(headA);
        b_length = list_length(headB);
        length_diff = a_length - b_length;
        while (length_diff > 0)
        {
            headA = headA->next;
            length_diff--;
        }
        while (length_diff < 0)
        {
            headB = headB->next;
            length_diff++;
        }

        while (headA && headB)
        {
            if (headA == headB)
                return headA;
            if (headA)
                headA = headA->next;
            if (headB)
                headB = headB->next;
        }

        return nullptr;
    }

    int list_length(ListNode *p)
    {
        int length = 0;
        ListNode *h = p;
        while (h)
        {
            length++;
            h = h->next;
        }
        return length;
    }
};
// @lc code=end
