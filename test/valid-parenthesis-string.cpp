#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    bool checkValidString(string s)
    {
        if(s.size()==1) return s[0]=='*';
        return deep(s, 0, s.size() - 1);
    }

    bool deep(string s, int start, int end)
    {
        if (end <= start)
            return true;

        if (s[start] == '*' && s[end] == '*')
            return deep(s, start + 1, end - 1) || deep(s, start , end - 1) || deep(s, start+1 , end ) ;
        else if (s[start] == '*')
        {
            return deep(s, start + 1, end) || deep(s, start + 1, end-1) ;
        }
        else if (s[end] == '*')
        {
            return  deep(s, start + 1, end-1) || deep(s, start, end - 1);
        }
        else
        {
            if (s[start] == s[end])
                return false;
            return deep(s, start + 1, end - 1);
        }
    }
};

int main()
{

    Solution s;
    cout << s.checkValidString("()()");
}
