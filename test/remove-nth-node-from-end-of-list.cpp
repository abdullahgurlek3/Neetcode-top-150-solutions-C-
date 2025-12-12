#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *last = head;
        int count = 0;
        while (last)
        {
            last = last->next;
            count++;
        }

        n = n % count;
        if (n == 0)
        {
            return head->next;
        }

        count = count - n;

        ListNode *cp = head;

        while (count > 1)
        {
            head = head->next;
            count--;
        }

        if (head->next)
            head->next = head->next->next;
        else
            head->next = nullptr;

        return cp;
    }
};

int main()
{
    vector<int> v = {1, 2, 3};
    ListNode listNode(v);
    Solution s;
    ListNode *ret = s.removeNthFromEnd(&listNode, 3);
    ret->print();
}
