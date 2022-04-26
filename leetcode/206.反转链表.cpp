/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode *reverseList(ListNode *head)
    {

        ListNode *res = new ListNode;
        ListNode *l = head;
        ListNode *r = new ListNode;

        if (head == nullptr)
            return nullptr;
        else if (head->next == nullptr)
            return head;
        else
            r = l->next;

        // at least two nodes in list
        while (l)
        {
            l->next = res->next;
            res->next = l;

            if (r == nullptr)
                break;

            l = r;
            r = r->next;
        }

        return res->next;
    }
};
// @lc code=end
