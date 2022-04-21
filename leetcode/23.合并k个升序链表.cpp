/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *res = new ListNode;
        ListNode *p = res;
        int min_value = INT32_MAX, min_index = 0;
        vector<int> list_valid(lists.size());
        for (int i = 0; i < lists.size(); i++)
            if (lists[i] != nullptr)
                list_valid[i] = 1;
            else
                list_valid[i] = 0;

        // print list_valid
        // cout << "list valid" << endl;
        // for (auto i : list_valid)
        //     cout << i << " ";
        // cout << endl;

        while (vector_sum(list_valid) > 1)
        {
            min_value = INT32_MAX;
            min_index = 0;
            for (int i = 0; i < lists.size(); i++)
            {
                if (list_valid[i])
                {
                    if (lists[i]->val < min_value)
                    {
                        min_value = lists[i]->val;
                        min_index = i;
                    }
                }
            }

            // choose the min value
            p->next = lists[min_index];
            p = p->next;
            lists[min_index] = lists[min_index]->next;
            if (lists[min_index] == nullptr)
                list_valid[min_index] = 0;
        }

        // if remain one list, append the list to p
        min_index == -1;
        for (int i = 0; i < lists.size(); i++)
            if (list_valid[i] == 1)
                min_index = i;
        if (min_index >= 0)
            p->next = lists[min_index];

        return res->next;
    }

    int vector_sum(const vector<int> &v)
    {
        int res = 0;
        for (auto i : v)
            res += i;
        return res;
    }
};
// @lc code=end
