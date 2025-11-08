#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    bool checkValidString(string s)
    {
        deque<char> a;
        deque<char> b;
        int i=0;
        while (i<s.size() && s[i]=='*')
        {
            i++;
            a.push_back('(');
        }
        
        return deep(s, a, b, i);
    }
    bool deep(string s, deque<char> &a, deque<char> &b, int start)
    {
        if (start == s.size())
            return a.size() <= b.size();
        if (s[start] == '(')
        {
            a.push_back('(');
            return deep(s, a, b, start + 1);
        }
        else if (s[start] == ')')
        {
            if (a.size() == 0)
            {
                if (b.size() == 0)
                    return false;
                else
                {
                    b.pop_back();
                }
            }
            else
            {
                a.pop_back();
            }
            return deep(s, a, b, start + 1);
        }
        else
        {
            b.push_back('*');
            return deep(s, a, b, start + 1);
        }
        return true;
    }

    string generatePositive(int step)
    {
        if (step == 0)
            return "()";
        string str = generatePositive(step - 1);
        if (rand() % 100)
            str[rand() % str.size()] = '*';
        if (rand() % 2)
        {
            return "()" + str;
        }
        else
        {
            return "(" + str + ")";
        }
    }
};

int main()
{

    srand(time(0));

    Solution s;
    cout << s.checkValidString("*(()");
}
