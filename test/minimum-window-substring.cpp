#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> m;
        int step = 0;
        for (char c : s)
        {
            m[c]++;
            step++;
        }

        unordered_map<char, int> w;
        int have = 0;
        int j = 0;
        string ret = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (m.count(s[i]))
            {
                w[s[i]]++;
                have++;
                if (m.size() == w.size())
                {
                    while (j < i)
                    {
                        if (!m.count(j))
                        {
                            j++;
                        }
                        else
                        {
                            w[j]--;
                            j++;
                            if (w[j] < m[j])
                                break;
                        }
                    }

                    string cur = s.substr(j, i - j + 1);
                    if (ret.size() == 0 || cur.size() < ret.size())
                    {
                        ret = cur;
                    }

                    j++;
                }
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC");
}
