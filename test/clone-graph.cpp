#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        map<int, Node *> m;
        Node *n = new Node(node->val);
        m[node->val] = n;

        deep(node, n, m);
        return n;
    }

    void deep(Node *node, Node *n, map<int, Node *> &m)
    {
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            if (!node->neighbors[i])
                continue;

            Node *nn;
            if (m.count(node->neighbors[i]->val))
            {
                nn = m[node->neighbors[i]->val];
            }
            else
            {
                nn = new Node(node->neighbors[i]->val);
                m[node->neighbors[i]->val] = nn;
                deep(node->neighbors[i], nn, m);
            }
            n->neighbors.push_back(nn);
        }
    }
};

int main()
{

    Node *node = new Node(3);
    node->neighbors = {new Node{1}, new Node{2}};

    Solution s;
    s.cloneGraph(node);
}
