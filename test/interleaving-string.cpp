#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        vector<vector<int>> mem(s1.size()+1, vector<int>(s2.size()+1));
        return deep(s1, 0, s2, 0, s3, 0, mem);
    }

    bool deep(string s1, int x1, string s2, int x2, string s3, int x3, vector<vector<int>> &memo)
    {
        if (memo[x1][x2])
            return false;
        if ((x1 == s1.size() && x2 == s2.size()) || x3 == s3.size())
            return x1 == s1.size() && x2 == s2.size() && x3 == s3.size();
        if (s1[x1] == s3[x3])
        {
            bool l = deep(s1, x1 + 1, s2, x2, s3, x3 + 1, memo);
            if (l)
                return true;
        }

        if (s2[x2] == s3[x3])
        {
            bool r = deep(s1, x1, s2, x2 + 1, s3, x3 + 1, memo);
            if (r)
                return true;
        }
        memo[x1][x2] = 1;
        return false;
    }
};

int main()
{

    Solution s;
    cout << s.isInterleave("ab", "cd", "abcd");
}
