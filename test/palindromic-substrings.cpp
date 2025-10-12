#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int countSubstrings(string s)
    {
        vector<vector<bool>> matrix(s.size(), vector<bool>(s.size(), false));
        int count=0;
        for (int y = s.size() - 1; y >= 0; y--)
        {
            for (int x = y; x < s.size(); x++)
            {
                if (s[y] == s[x] && (x - y <= 2 || matrix[y + 1][x - 1]))
                {
                    matrix[y][x] = true;
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution s;
    cout << s.countSubstrings("aaa") << endl;
}
