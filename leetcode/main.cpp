#include "headfile.h"
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;
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

    l1->val = 3;
    l2->val = 2;
    l3->val = 0;
    l4->val = -4;
    l5->val = 5;

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l2;
    // l5->next = nullptr;

    bool flag = s.hasCycle(l1);
    cout << flag << endl;
    // while (res != nullptr)
    // {
    //     cout << res->val << " ";
    //     res = res->next;
    // }

    return 0;
}