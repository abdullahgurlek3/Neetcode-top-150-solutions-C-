#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
        {
            return list2;
        }

        if (!list2)
        {
            return list1;
        }

        if (list2->val < list1->val)
        {
            ListNode *tmp = list1;
            list1 = list2;
            list2 = tmp;
        }

        ListNode *head = list1;

        while (list1 && list2)
        {
            if (list1->next && list1->next->val > list2->val)
            {
                ListNode *n = list1->next;
                list1->next = list2;
                list2 = n;
            }
            if (!list1->next)
            {
                list1->next = list2;
                break;
            }

            list1 = list1->next;
        }

        return head;
    }
};

int main()
{
    vector<int> v1 = {1, 4, 5};
    ListNode listNode1(2);

    vector<int> v2 = {2, 3, 5};
    ListNode listNode2(1);

    // 1[4] 4[5]
    // 2[3] 3[5]

    Solution s;
    ListNode *reversed = s.mergeTwoLists(&listNode1, &listNode2);
    reversed->print();
}
