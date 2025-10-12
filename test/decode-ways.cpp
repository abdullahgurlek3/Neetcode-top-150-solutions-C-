#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int numDecodings(string s)
    {
        vector<int> v(s.size() + 1);
        v[0] = 1;
        v[1] = s[0] == '0' ? 0 : 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != '0')
            {
                v[i + 1] = v[i];
            }
            if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6'))
            {
                v[i + 1] += v[i - 1];
            }
        }

        return v[v.size() - 1];
    }
};

int main()
{
    Solution s;
    cout << s.numDecodings("06") << endl;
}
