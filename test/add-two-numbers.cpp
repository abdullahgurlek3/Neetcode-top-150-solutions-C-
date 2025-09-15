#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int r = 0;
        ListNode *root = l1;
        ListNode *last = l1;

        while (l1 && l2)
        {
            l1->val += l2->val + r;

            if (l1->val > 9)
            {
                l1->val %= 10;
                r = 1;
            }else{
                r=0;
            }
            last = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (!l1)
            last->next = l2;
        ListNode *plast = last;

        last = last->next;
        while (last)
        {
            last->val += r;
            if (last->val > 9)
            {
                last->val %= 10;
                r = 1;
            }else{
                r=0;
            }
            plast = last;
            last = last->next;
        }

        if (r > 0)
        {
            plast->next = new ListNode(r);
        }

        return root;
    }
};

int main()
{
    vector<int> v = {9, 9, 9, 9};
    ListNode listNode(v);

    vector<int> v2 = {9, 9, 9, 9};
    ListNode listNode2(v2);

    Solution s;
    ListNode *ret = s.addTwoNumbers(&listNode, &listNode2);
    ret->print();
}
