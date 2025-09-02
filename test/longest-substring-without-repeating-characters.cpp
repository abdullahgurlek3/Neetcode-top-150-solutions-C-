#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> m;

        int total = 0;
        int mx = total;
        for (int i = 0; i < s.size(); i++)
        {
            if (m.count(s[i]))
            {
                i = m[s[i]];
                m.clear();
                if (mx < total)
                    mx = total;
                total = 0;
            }
            else
            {
                m[s[i]] = i;
                total++;
            }
        }
        if (mx < total)
            mx = total;
        return mx;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring(" ");
}
