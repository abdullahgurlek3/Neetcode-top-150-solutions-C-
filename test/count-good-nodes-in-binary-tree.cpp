#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int goodNodes(TreeNode *root)
    {
        int count = 0;
        deep(root, root->val, &count);
        return count;
    }

    void deep(TreeNode *root, int mx, int *count)
    {
        if (root)
        {
            if (root->val > mx)
            {
                mx = root->val;
                (*count)++;
            }
            deep(root->left, mx, count);
            deep(root->right, mx, count);
        }
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    Solution s;
    cout << (s.goodNodes(tree));
}
