#include "iostream"
#include "helper.h"
#include "map"
#include <utility>

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    set<Node *> visited;
    map<Node *, Node *> b;
    deque<pair<Node *, Node *>> d;
    Node *copyRandomList(Node *head)
    {
        if (visited.count(head) || !head)
            return head;
        visited.insert(head);

        Node *root = new Node(head->val);
        b[head] = root;
        if (b.count(head->random))
            root->random = b[head->random];
        else
            d.push_back({head->random, root});

        while (d.size() > 0 && b.count(d.back().first))
        {
            d.back().second->random = b[d.back().first];
            d.pop_back();
        }

        cout << d.size() << endl;

        root->next = copyRandomList(head->next);
        return root;
    }
};

int main()
{
    Node node(1);
    node.next = new Node(2);
    (*node.next).next = new Node(3);

    Solution s;
    Node *ret = s.copyRandomList(&node);
    while (ret)
    {
        cout << ret->val << endl;
        ret = ret->next;
    }
}
