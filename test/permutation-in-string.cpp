#include "iostream"
#include "helper.h"
#include "unordered_set"

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if(s1.size()>s2.size()) return false;
        unordered_map<char, int> m2;
        unordered_map<char, int> m1;
        int i = 0;
        for (; i < s1.size(); i++)
        {
            if (m2.count(s2[i]))
            {
                m2[s2[i]]++;
            }
            else
            {
                m2[s2[i]] = 1;
            }
            if (m1.count(s1[i]))
            {
                m1[s1[i]]++;
            }
            else
            {
                m1[s1[i]] = 1;
            }
        }

        bool found = true;
                for (const auto a : m1)
                {
                    if (a.second != m2[a.first])
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                    return true;
        
        for (; i < s2.size(); i++)
        {
             if (m2.count(s2[i]))
            {
                m2[s2[i]]++;
            }
            else
            {
                m2[s2[i]] = 1;
            }
            m2[s2[i-s1.size()]]--;
                bool found = true;
                for (const auto a : m1)
                {
                    if (a.second != m2[a.first])
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                    return true;
            
           
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.checkInclusion("ab", "eidbaooo");
}
