#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root)
        {
            if (isSameTree(root, subRoot))
                return true;
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        return false;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p && q)
        {
            if (p->val != q->val)
                return false;
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else if (!p && !q)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    TreeNode *tree2 = new TreeNode(1);

    Solution s;
    cout << s.isSubtree(tree, tree2);
}
