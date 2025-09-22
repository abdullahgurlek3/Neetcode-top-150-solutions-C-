#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return maxDepth(root, 0);
    }

    int maxDepth(TreeNode *root, int level)
    {
        if (root)
        {
            return max(maxDepth(root->left, level + 1)+1, maxDepth(root->right, level + 1)+1);
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
    cout << s.maxDepth(tree);
}
