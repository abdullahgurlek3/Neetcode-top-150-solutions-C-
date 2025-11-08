#include "iostream"
#include "../../test/helper.h"
#include "map"
class Solution
{
public:
    map<string, int> cache;
    int longestBalanced(string s)
    {
        map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }
        return longestBalancedSub(s, 0, s.size() - 1, m);
    }

    int longestBalancedSub(string s, int start, int end, map<char, int> &m)
    {

        int count = m[s[start]];
        bool f = true;
        for (const auto item : m)
        {
            if (item.second != count)
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            return end - start + 1;
        }
        map<char, int> ml = m;
        ml[s[start]]--;
        if (ml[s[start]] == 0)
        {
            ml.erase(s[start]);
        }

        map<char, int> mr = m;
        mr[s[end]]--;
        if (mr[s[end]] == 0)
        {
            mr.erase(s[end]);
        }

        return max(longestBalancedSub(s, start + 1, end, ml), longestBalancedSub(s, start, end - 1, mr));
    }
};

int main()
{

    Solution s;
    cout << s.longestBalanced("bebdadeacaaddbacbdae©leetcode");
}
