#include "headfile.h"
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

int main()
{

    ListNode *l1 = new ListNode;
    ListNode *l2 = new ListNode;
    ListNode *l3 = new ListNode;
    ListNode *l4 = new ListNode;
    ListNode *l5 = new ListNode;
    ListNode *l6 = new ListNode;
    ListNode *l7 = new ListNode;
    ListNode *l8 = new ListNode;
    Solution s;

    l1->val = 1;
    l2->val = 2;
    l3->val = 3;
    l4->val = 4;
    l5->val = 5;

    l1->next = l2;
    l2->next = nullptr;
    l3->next = l4;
    l4->next = l5;
    l5->next = nullptr;

    ListNode *head = l1;
    cout << "list data: ";
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    ListNode *res = s.removeNthFromEnd(l1, 1);

    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}