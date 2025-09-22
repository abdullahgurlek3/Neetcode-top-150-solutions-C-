#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    string decodeString(string s)
    {
        string nmr = "";

        deque<string> dn;
        deque<string> ds;
        ds.push_back("");

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] <= 'z' && s[i] >= 'a')
            {
                ds.back() += s[i];
            }
            else if (s[i] <= '9' && s[i] >= '0')
            {
                nmr += s[i];
            }
            else if (s[i] == '[')
            {
                dn.push_back(nmr);
                ds.push_back("");
                nmr = "";
            }
            else
            {
                string last = ds.back();
                ds.pop_back();

                int n = stoi(dn.back());
                dn.pop_back();
                for (int k = 0; k < n; k++)
                {
                    ds.back() += last;
                }
            }
        }
        return ds.back();
    }
};

int main()
{
    Solution s;
    cout << s.decodeString("3[a2[c]ef]abc") << endl;
}
