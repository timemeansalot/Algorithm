#include "headfile.h"

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *p = head, *first = head, *l = head, *r = head;
        int count = 1;

        while (count <= right)
        {

            if (count == left)
            {
                p = l;
                first = r;
            }

            if (count > left)
            {
                l->next = p->next;
                p->next = l;
            }

            l = r;
            r = r->next;
            count++;
        }

        first->next = l;
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
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    res = s.reverseBetween(n1, 2, 4);

    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}