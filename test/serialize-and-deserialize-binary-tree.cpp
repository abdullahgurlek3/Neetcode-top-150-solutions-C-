#include "iostream"
#include "helper.h"
#include "map"

// class Codec
// {
// public:
//     // Encodes a tree to a single string.
//     string serialize(TreeNode *root)
//     {
//         if (root)
//         {
//             string ret = to_string(root->val) + "[" + serialize(root->left) + "]" + "[" + serialize(root->right) + "]";
//             return ret;
//         }
//         return "";
//     }

//     // Decodes your encoded data to tree.
//     TreeNode *deserialize(string data)
//     {
//         if (data.size() == 0)
//             return nullptr;
//         if (data[0] == '{' || data[0] == '[')
//             return nullptr;

//         int i = 0;
//         while (data[i] != '[')
//         {
//             i++;
//         }

//         TreeNode *root = new TreeNode(stoi(data.substr(0, i)));

//         int count = 1;
//         i++;
//         int start = i;
//         while (i < data.size() && count != 0)
//         {
//             if (data[i] == '[')
//                 count++;
//             else if (data[i] == ']')
//                 count--;
//             i++;
//         }

//         root->left = deserialize(data.substr(start, i - start - 1));
//         root->right = deserialize(data.substr(i + 1, data.size() - i - 2));

//         return root;
//     }
// };

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        deque<TreeNode*> q;
        q.push_back(root);

        string str="";

        while (q.size()>0)
        {
            
        }
        
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {

        
        return nullptr;
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    Codec c;
    string str = c.serialize(tree);
    cout << str << endl;
    TreeNode *sr = c.deserialize(str);
    cout << sr->left->val << endl;
    cout << sr->right->val << endl;
}
