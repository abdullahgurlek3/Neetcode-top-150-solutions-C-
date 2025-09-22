#include "iostream"
#include "helper.h"
#include "map"

/* class Solution
{
public:
    vector<int> v;
    int kthSmallest(TreeNode *root, int k)
    {
        if (root)
        {
            int l = kthSmallest(root->left, k);
            if (l > -1)
                return l;

            v.push_back(root->val);
            if (v.size() == k)
                return v[k - 1];
            int r = kthSmallest(root->right, k);
            if (r > -1)
                return r;
        }
        return -1;
    }
}; */

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int tmp = 0;
        return kthSmallest(root, k, &tmp);
    }

    int kthSmallest(TreeNode *root, int k, int *n)
    {
        if (root)
        {
            int l = kthSmallest(root->left, k, n);
            if (l > -1)
                return l;
            (*n)++;
            if (*n == k)
                return root->val;
            int r = kthSmallest(root->right, k, n);
            if (r > -1)
                return r;
        }
        return -1;
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    Solution s;
    cout << (s.kthSmallest(tree, 0));
}
