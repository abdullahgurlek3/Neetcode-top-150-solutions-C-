#include "iostream"
#include "helper.h"
#include "set"

// class Solution
// {
// public:
//     bool hasCycle(ListNode *head)
//     {
//         unordered_map<ListNode *, bool> s;
//         while (head)
//         {
//             if (s.count(head))
//             {
//                 return true;
//             }
//             s[head] = true;
//             head = head->next;
//         }
//         return false;
//     }
// };

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
        {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (slow != fast &&fast  && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow == fast;
    }
};

int main()
{
    ListNode listNode(1);
    listNode.next = &listNode;

    Solution s;
    cout << s.hasCycle(&listNode);
}
