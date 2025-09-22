#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        int i = 0;
        ListNode *dummy = NULL;
        ListNode *back = NULL;
        ListNode *prev = NULL;

        ListNode *ret = new ListNode();
        ListNode *root = ret;
        while (head && i < k)
        {
            ListNode *n = head->next;
            head->next = dummy;
            if (!back)
                back = head;
            dummy = head;
            head = n;
            i++;
            if (i == k)
            {
                i = 0;
                ret->next = dummy;
                ret = back;
                dummy = NULL;
                back = NULL;
            }
        }
        ListNode *dr = nullptr;
        while (dummy)
        {
            ListNode *n = dummy->next;
            dummy->next = dr;
            dr = dummy;
            dummy = n;
        }

        ret->next = dr;
        return root->next;
    }
};

int main()
{
    ListNode listNode({1, 2, 3, 4, 12, 13, 16, 20});

    Solution s;
    s.reverseKGroup(&listNode, 2)->print();
}
