#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        map<int, bool> d;
        return wb(s, wordDict, 0, d);
    }

    bool wb(string s, vector<string> &wordDict, int start, map<int, bool> &d)
    {
        if (start > s.size())
            return false;
        if (start == s.size())
            return true;

        if (d.count(start))
            return d[start];
        for (string w : wordDict)
        {
            bool found = true;
            for (int i = 0; i < w.size(); i++)
            {
                if (start + i >= s.size())
                {
                    found = false;
                    break;
                }
                if (w[i] != s[start + i])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                if (wb(s, wordDict, start + w.size(), d))
                    return true;
            }
        }
        d[start] = false;
        return false;
    }
};

int main()
{

    Solution s;
    vector<string> st = {"leet", "code"};
    cout << s.wordBreak("leetcode", st);
}
