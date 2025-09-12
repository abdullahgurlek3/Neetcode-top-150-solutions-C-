#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {

        ListNode *tail = NULL;
        while (head)
        {
            ListNode *n = head->next;
            head->next = tail;
            tail = head;
            head = n;
        }
        // 1[2] 2[3] 3[4]
        return tail;
    }
};

// 1[2] 2[3] 3[4] 4[5]

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode listNode(v);
    Solution s;
    ListNode* reversed = s.reverseList(&listNode);
    reversed->print();
}
