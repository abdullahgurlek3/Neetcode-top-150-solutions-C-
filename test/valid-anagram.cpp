#include "iostream"
#include "helper.h"

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int ar1['z' - 'a' + 1];
        int ar2['z' - 'a' + 1];

        for (char c : s)
        {
            ar1[c - 'a']++;
        }

        for (char c : t)
        {
            ar2[c - 'a']++;
        }

        for (int i = 0; i < 'z' - 'a' + 1; i++)
        {
            if (ar1[i] != ar2[i])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    s.isAnagram("anagram", "nagaram");
}
