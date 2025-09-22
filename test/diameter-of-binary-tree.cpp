#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int val = 0;
        maxDepth(root, &val);
        return val;
    }

    int maxDepth(TreeNode *root, int *val)
    {
        if (root)
        {
            int l = maxDepth(root->left, val);
            int r = maxDepth(root->right, val);
            if (l + r > *val)
                *val = l + r;
            return max(l + 1, r + 1);
        }
        return 0;
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    Solution s;
    cout << s.diameterOfBinaryTree(tree);
}
