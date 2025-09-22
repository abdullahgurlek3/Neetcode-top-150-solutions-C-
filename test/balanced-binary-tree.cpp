#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return isBalancedSub(root).first;
    }

    pair<bool, int> isBalancedSub(TreeNode *root)
    {
        if (root)
        {
            pair<bool, int> l = isBalancedSub(root->left);
            if (!l.first)
            {
                return {false, 0};
            }

            pair<bool, int> r = isBalancedSub(root->right);
            if (!r.first)
            {
                return {false, 0};
            }
            return {abs(r.second - l.second) < 2, max(r.second + 1, l.second + 1)};
        }
        return {true, 0};
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    Solution s;
    cout << s.isBalanced(tree);
}
