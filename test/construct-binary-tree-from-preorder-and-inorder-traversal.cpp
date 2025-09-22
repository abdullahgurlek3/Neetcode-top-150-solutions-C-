#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size()==0)
        {
            return nullptr;
        }
        
        int j = 0;
        while (inorder[j] != preorder[0])
        {
            j++;
        }

        TreeNode *root = new TreeNode(preorder[0]);
        vector<int> leftpre(preorder.begin() + 1, preorder.begin() + j + 1);
        vector<int> leftin(inorder.begin(), inorder.begin() + j);

        root->left = buildTree(leftpre, leftin);

        vector<int> rightpre(preorder.begin() + j + 1, preorder.end());
        vector<int> rightin(inorder.begin() + j + 1, inorder.end());

        root->right = buildTree(rightpre, rightin);

        return root;
    }
};

int main()
{
    vector<int> l1 = {1, 2, 4, 5, 3};
    vector<int> l2 = {4, 2, 5, 1, 3};

    Solution s;
    TreeNode *tree = (s.buildTree(l1, l2));
    tree->preorder();
}
