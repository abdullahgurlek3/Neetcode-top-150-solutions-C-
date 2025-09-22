#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int mx = root->val;
        maxPathSum(root, &mx);
        return mx;
    }
    int maxPathSum(TreeNode *root, int *mx)
    {
        if (root)
        {
            int left = maxPathSum(root->left, mx);
            int right = maxPathSum(root->right, mx);
            if (left + right + root->val > *mx)
                *mx = left + right + root->val;
            if (left + root->val > *mx)
                *mx = left + root->val;
            if (right + root->val > *mx)
                *mx = right + root->val;
            if (root->val > *mx)
                *mx = root->val;
            return max(max(left + root->val, right + root->val), root->val);
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
    cout << (s.maxPathSum(tree));
}
