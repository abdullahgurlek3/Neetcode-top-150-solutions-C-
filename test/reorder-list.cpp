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
        ListNode *tail = NULL;
        if (fast)
        {
            s.push(slow);
        }
        else
        {
            tail = new ListNode(slow->val);
        }

        slow = slow->next;
        while (s.size() > 0)    
        {
            ListNode *n = slow->next;
            slow->next = tail;
            s.top()->next = slow;
            tail = s.top();
            s.pop();
            slow = n;
        }
    };
};
// 1[2] 2[3] 3[4] 4[5] 5[6]

int main()
{
    vector<int> v = {1, 2, 3, 4, 5,6};
    ListNode listNode(v);
    Solution s;
    s.reorderList(&listNode);
    listNode.print();
}
