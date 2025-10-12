#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int mx = 0;
        int mi = 0;

        int n = s.size();

        vector<vector<bool>> matrix(n, vector<bool>(n, false));

        for (int y = n - 1; y >= 0; y--)
        {
            for (int x = y; x < n; x++)
            {
                if (s[x] == s[y] && (x - y <= 2 || matrix[y + 1][x - 1]))
                {
                    matrix[y][x] = true;
                    if (mx<(x - y + 1) )
                    {
                        mi = y;
                        mx = x - y + 1;
                    }
                }
            }
        }  
        return s.substr(mi, mx);
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("aacabdkacaa") << endl;
}
