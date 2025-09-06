#include "iostream"
#include "helper.h"
#include "unordered_set"
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if(t.size()>s.size()) return "";
        unordered_map<char, int> mo;

        for (int i = 0; i < t.size(); i++)
        {
            mo[t[i]]++;
        }

        string ret = "";

        for (int i = 0; i < s.size(); i++)
        {
            unordered_map<char, int> cp;
            for (int j = i; j < s.size(); j++)
            {
                if(j>0 && s[j]==s[j-1]){
                    continue;
                }
                int cur = mo.count(s[j]);
                if (cur > 0)
                {
                    cp[s[j]]++;

                    bool found = true;
                    for (const auto a : mo)
                    {
                        int count = cp[a.first];
                        if (count < a.second)
                        {
                            found = false;
                            break;
                        }
                    }

                    if (found)
                    {

                        string current = s.substr(i, j - i + 1);
                        if (ret == "" || ret.size() > current.size())
                        {
                            ret = current;
                        }

                        break;
                    }
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
