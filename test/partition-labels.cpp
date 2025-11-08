#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (m.count(c))
            {
                for (int j = m[c]; j <= i; j++)
                    m[s[j]] = m[c];
            }
            else
            {
                m[c] = i;
            }
        }
        int count = 1;
        vector<int> ret;
        for (int i = 1; i < s.size(); i++)
        {
            if (m[s[i]] == m[s[i - 1]])
            {
                count++;
            }
            else
            {
                ret.push_back(count);
                count = 1;
            }
        }
        ret.push_back(count);

        return ret;
    }
};

int main()
{

    Solution s;
    print_v(s.partitionLabels("abcdc"));
}
