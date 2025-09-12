#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        stack<ListNode *> s;
        while (fast && fast->next)
        {
            s.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }

        while (slow)
        {
            s.top()->next = slow;
            s.pop();
            ListNode *n = slow->next;
            slow = n;
        }
    };
};
// 1[2] 2[3] 3[4] 4[5]

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    ListNode listNode(v);
    Solution s;
    s.reorderList(&listNode);
    listNode.print();
}
