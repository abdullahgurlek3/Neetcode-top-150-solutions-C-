#include "iostream"
#include "helper.h"
#include "unordered_set"

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_set<char> st;
        for (char c : s)
        {
            st.insert(c);
        }

        int mx = 0;

        for (char c : st)
        {
            int count = 0;
            int l = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == c)
                {
                    count++;
                }
                while ((i - l + 1) - count > k)
                {
                    if (s[l] == c)
                    {
                        count--;
                    }
                    l++;    
                }
                cout << l << " " << i << " " << s.substr(l, i - l+1) << "    "<< c << endl;
                mx=max(mx,i-l+1); 
            }
        }

        return mx;
    };
};

int main()
{
    Solution s;
    cout << s.characterReplacement("AABABBA", 1);
}
