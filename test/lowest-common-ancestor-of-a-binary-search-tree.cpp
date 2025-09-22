#include "iostream"
#include "helper.h"
#include "map"
/*
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<bool> v(2);
        return lowestCommonAncestorSub(root, p, q).first;
    }

    pair<TreeNode *, vector<bool>> lowestCommonAncestorSub(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root)
        {
            pair<TreeNode *, vector<bool>> l = lowestCommonAncestorSub(root->left, p, q);
            if (l.first)
                return l;

            pair<TreeNode *, vector<bool>> r = lowestCommonAncestorSub(root->right, p, q);
            if (r.first)
                return r;

            pair<TreeNode *, vector<bool>> ret = {nullptr, {l.second[0] || r.second[0], l.second[1] || r.second[1]}};
            if (p == root)
            {
                ret.second[0] = true;
            }

            if (q == root)
            {
                ret.second[1] = true;
            }
            if (ret.second[0] && ret.second[1])
            {
                ret.first = root;
            }

            return ret;
        }
        return {nullptr, {false, false}};
    }
};
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root)
        {
            if (p->val < root->val && q->val < root->val)
            {
                return lowestCommonAncestor(root->left, p, q);
            }
            else if (p->val > root->val && q->val > root->val)
            {
                return lowestCommonAncestor(root->right, p, q);
            }
            else if (min(p->val, q->val) < root->val || max(p->val, q->val) > root->val)
            {
                return root;
            }
            else if (p->val == root->val || q->val == root->val)
            {
                return root;
            }
        }
        return nullptr;
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    Solution s;
    cout << s.lowestCommonAncestor(tree, tree->left, tree->right);
}
