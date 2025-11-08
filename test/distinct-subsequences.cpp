#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int numDistinct(string t, string s)
    {

        vector<vector<long long>> v(s.size(), vector<long long>(t.size()));
        for (int y = s.size() - 1; y >= 0; y--)
        {
            for (int x = t.size() - 1; x >= 0; x--)
            {
                if (s[y] == t[x])
                {
                    v[y][x]++;
                }
            }
        }

        for (int y = s.size() - 2; y >= 0; y--)
        {
            int p = 0;
            for (int x = t.size() - 1; x >= 0; x--)
            {
                if (v[y][x])
                {
                    v[y][x] = p;
                    if (v[y][x] > INT_MAX)
                    {
                        v[y][x] %= INT_MAX;
                    }
                }
                else
                {
                    v[y][x] = 0;
                }
                p += v[y + 1][x];
            }
        }

        int total = 0;
        for (int x = 0; x < t.size(); x++)
            total += v[0][x];

        return total;
    }
};

int main()
{

    Solution s;
    cout << s.numDistinct("babgbag", "bag");
}
