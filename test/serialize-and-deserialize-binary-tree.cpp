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
        deque<TreeNode *> q;

        q.push_back(root);

        vector<string> strs;

        while (q.size() > 0)
        {
            TreeNode *back = q.front();
            q.pop_front();

            if (back)
            {
                strs.push_back(to_string(back->val));
                q.push_back(back->left);
                q.push_back(back->right);
            }
            else
            {
                strs.push_back("-");
            }
        }

        string str = "";
        for (string x : strs)
        {
            str += x + ",";
        }
        return str.substr(0, str.size() - 1);
    }

    TreeNode *
    deserialize(string data)
    {
        if (data == "-")
        {
            return nullptr;
        }

        int i = 0;
        while (i < data.size() && data[i] != ',')
            i++;
        TreeNode *root = new TreeNode(stoi(data.substr(0, i)));
        deque<TreeNode *> q;
        q.push_back(root);
        TreeNode *main = root;
        i++;
        while (i < data.size() && q.size() > 0)
        {
            root = q.front();
            q.pop_front();
            int start = i;
            while (i < data.size() && data[i] != ',')
                i++;

            if (data.substr(start, i - start) != "-")
            {
                root->left = new TreeNode(stoi(data.substr(start, i - start)));
                q.push_back(root->left);
            }

            if (i == data.size())
                break;
            i++;
            start = i;

            while (i < data.size() && data[i] != ',')
                i++;
            if (data.substr(start, i - start) != "-")
            {
                root->right = new TreeNode(stoi(data.substr(start, i - start)));
                q.push_back(root->right);
            }
            i++;
        }

        return main;
    }
};
//    1
//  2   3
// 4 5 6 7
//

// 1 3 7 6 5 2 4
int main()
{
    TreeNode *tree = deserializeBFS("1,2,3,4,5,6,7,8");

    Codec c;
    string str = c.serialize(tree);
    cout << str << endl;
    TreeNode *sr = c.deserialize(str);
    cout << sr << endl;
    cout << sr->right->val << endl;

    tree->preorder();
}
