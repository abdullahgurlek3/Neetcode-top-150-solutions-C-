#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    TreeNode *last = NULL;

    bool isValidBST(TreeNode *root)
    {
        if (root)
        {
            bool l = isValidBST(root->left);
            if (!l)
            {
                return false;
            }

            if (last && root)
            {
                if (last->val >= root->val)
                {
                    return false;
                }
            }
            last = root;
            return isValidBST(root->right);
        }
        return true;
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    Solution s;
    cout << (s.isValidBST(tree));
}
