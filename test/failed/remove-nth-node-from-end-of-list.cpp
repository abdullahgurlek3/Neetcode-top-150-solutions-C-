#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        if (!fast)
        {
            return NULL;
        }

        int count = 0;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            count += 2;
        }

        count += fast ? 2 : 1;

        cout << count << endl;

        int index = count - n - 2;
        if (index<0)
        {
            index+=count;
        }
        
       
        ListNode *ag = head;


        cout << index << " index "<< endl;
        return head;
    }
};

int main()
{
    vector<int> v = {1, 2};
    ListNode listNode(v);
    Solution s;
    ListNode *ret = s.removeNthFromEnd(&listNode, 2);
    ret->print();
}
