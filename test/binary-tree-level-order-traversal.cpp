#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;

        if (!root)
        {
            return ret;
        }

        vector<TreeNode *> q;
        q.push_back(root);

        while (q.size() > 0)
        {
            vector<TreeNode *> sub;
            vector<int> cur;

            for (int i = 0; i < q.size(); i++)
            {
                if (q[i]->left)
                {
                    sub.push_back(q[i]->left);
                }
                if (q[i]->right)
                {
                    sub.push_back(q[i]->right);
                }
                cur.push_back(q[i]->val);
            }
            q = sub;
            ret.push_back(cur);
        }
        return ret;
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    Solution s;
    (s.levelOrder(tree));
}
