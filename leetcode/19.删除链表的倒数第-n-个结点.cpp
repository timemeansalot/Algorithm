/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (head == nullptr)
            return head;
        ListNode *res = new ListNode;
        res->next = head;
        ListNode *left = res;
        ListNode *right = left;

        while (n > 0)
        {
            right = right->next;
            if (right == nullptr)
                break;
            n--;
        }
        if (n)
            return head;

        // right = right->next;
        while (right->next)
        {
            right = right->next;
            left = left->next;
        }

        left->next = left->next->next;

        return res->next;
    }
};
// @lc code=end
