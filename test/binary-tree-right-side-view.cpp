#include "iostream"
#include "helper.h"
#include "map"
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ret;
        deep(root, &ret, 0);
        return ret;
    }

    void deep(TreeNode *root, vector<int> *ret, int level)
    {
        if (root)
        {
            if (level+1 > (*ret).size())
            {
                (*ret).resize(level+1);
            }
            
            (*ret)[level] = root->val;

            deep(root->left, ret, level + 1);
            deep(root->right, ret, level + 1);
        }
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    Solution s;
   print_v(s.rightSideView(tree));
}
