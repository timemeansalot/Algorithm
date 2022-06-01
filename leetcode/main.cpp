#include "headfile.h"

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

int main()
{
    ListNode *n1 = new ListNode;
    ListNode *n2 = new ListNode;
    ListNode *n3 = new ListNode;
    ListNode *n4 = new ListNode;
    ListNode *n5 = new ListNode;
    ListNode *res = new ListNode;
    Solution s;
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    n5->val = 5;

    n1->next = n2;
    n2->next = nullptr;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    res = s.reverseBetween(n1, 1, 2);

    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}