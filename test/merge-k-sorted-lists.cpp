#include "iostream"
#include "helper.h"
#include "map"

/*
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ret = new ListNode(0);
        ListNode *root = ret;
        while (lists.size() > 0)
        {
            if (!lists[0])
            {
                lists.erase(lists.begin());
                continue;
            }
            int mn = lists[0]->val;
            int mnl = 0;
            for (int i = 0; i < lists.size(); i++)
            {
                if (!lists[i])
            {
                continue;
            }
                if (lists[i]->val < mn)
                {
                    mn = lists[i]->val;
                    mnl = i;
                }
            }

            if (lists[mnl])
            {
                ret->next = new ListNode(lists[mnl]->val);
                ret = ret->next;
                lists[mnl] = lists[mnl]->next;
            }
            if (!lists[mnl])
            {
                lists.erase(lists.begin() + mnl);
            }
        }
        return root->next;
    }
};
*/

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        if (lists.size() == 1)
        {
            return lists[0];
        }
        ListNode *merged = mergeNodes(lists[lists.size() - 1], lists[lists.size() - 2]);
        lists.pop_back();
        lists[lists.size() - 1] = merged;
        return mergeKLists(lists);
    }

    ListNode *mergeNodes(ListNode *l1, ListNode *l2)
    {
        if (!l1)
        {
            return l2;
        }
        if (!l2)
            return l1;

        if (l1->val > l2->val)
        {
            swap(l1, l2);
        }

        ListNode *root = l1;
        while (l1->next && l2)
        {
            if (l1->next && l1->next->val > l2->val)
            {
                ListNode *n = l1->next;
                l1->next = l2;
                l2 = n;
            }
            else
            {
                l1 = l1->next;
            }
        }
        l1->next = l2;
        return root;
    }
};

int main()
{
    ListNode listNode({1, 2, 3, 4, 12, 13});
    ListNode listNode2({7, 8, 9, 10});
    ListNode listNode3({1, 2, 3, 99});

    vector<ListNode *> v({&listNode2, &listNode3, &listNode});
    Solution s;
    s.mergeKLists(v)->print();
}
