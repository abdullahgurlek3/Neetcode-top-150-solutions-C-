#include "iostream"
#include "helper.h"
#include "map"

// class Solution
// {
// public:
//     int evalRPN(vector<string> &tokens)
//     {
//         if (tokens.size() == 1)
//         {
//             return stoi(tokens[0]);
//         }
//         {
//             /* code */
//         }

//         for (int i = 2; i < tokens.size(); i++)
//         {
//             if (tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/")
//             {
//                 bool x = tokens[i - 1] == "*" || tokens[i - 1] == "+" || tokens[i - 1] == "-" || tokens[i - 1] == "/";
//                 bool y = tokens[i - 2] == "*" || tokens[i - 2] == "+" || tokens[i - 2] == "-" || tokens[i - 2] == "/";
//                 if (!x && !y)
//                 {
//                     int ret;
//                     int a = stoi(tokens[i - 2]);
//                     int b = stoi(tokens[i - 1]);

//                     if (tokens[i] == "*")
//                     {
//                         ret = a * b;
//                     }
//                     else if (tokens[i] == "+")
//                     {
//                         ret = a + b;
//                     }
//                     else if (tokens[i] == "-")
//                     {
//                         ret = a - b;
//                     }
//                     else if (tokens[i] == "/")
//                     {
//                         ret = a / b;
//                     }
//                     tokens[i - 2] = to_string(ret);
//                     tokens.erase(tokens.begin() + i);
//                     tokens.erase(tokens.begin() + i - 1);
//                     return evalRPN(tokens);
//                 }
//             }
//         }
//         return 1;
//     }
// };

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        vector<int> v;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/")
            {
                int a = v[v.size() - 2];
                int b = v[v.size() - 1];
                v.pop_back();
                v.pop_back();
                int ret;
                if (tokens[i] == "*")
                {
                    ret = a * b;
                }
                else if (tokens[i] == "+")
                {
                    ret = a + b;
                }
                else if (tokens[i] == "-")
                {
                    ret = a - b;
                }
                else if (tokens[i] == "/")
                {
                    ret = a / b;
                }
                v.push_back(ret);
            }
            else
            {
                v.push_back(stoi(tokens[i]));
            }
        }
        return v[0];
    }
};

int main()
{
    Solution s;
    vector<string> v = {"2", "1", "+", "3", "*"};
    cout << (s.evalRPN(v));
}
