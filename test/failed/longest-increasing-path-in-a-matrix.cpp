#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        map<char, vector<vector<int>>> m;
        m['u'] = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        m['d'] = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        m['l'] = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        m['r'] = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        m['c'] = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));

        int mx = 0;
        for (int y = 0; y < matrix.size(); y++)
        {
            for (int x = 0; x < matrix[0].size(); x++)
            {
                int ret = deep(matrix, m, y, x, 1, 'c');
                if (ret > mx)
                    mx = ret;
            }
        }
        return mx;
    }
    int deep(vector<vector<int>> &matrix, map<char, vector<vector<int>>> &m, int y, int x, int level, char direction)
    {
        if (m[direction][y][x] > 0)
            return m[direction][y][x] + 1;

        int mx = level;
        if (y + 1 < matrix.size() && matrix[y + 1][x] > matrix[y][x])
        {
            int a = deep(matrix, m, y + 1, x, level + 1, 'u');
            mx = max(a, mx);
        }

        if (y > 0 && matrix[y - 1][x] > matrix[y][x])
        {
            int a = deep(matrix, m, y - 1, x, level + 1, 'd');
            mx = max(a, mx);
        }

        if (x + 1 < matrix[0].size() && matrix[y][x + 1] > matrix[y][x])
        {
            int a = deep(matrix, m, y, x + 1, level + 1, 'r');
            mx = max(a, mx);
        }

        if (x > 0 && matrix[y][x - 1] > matrix[y][x])
        {
            int a = deep(matrix, m, y, x - 1, level + 1, 'l');
            mx = max(a, mx);
        }
        if (mx > m[direction][y][x])
            m[direction][y][x] = mx;
        return mx;
    }
};

int main()
{
    vector<vector<int>> v = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}};
    Solution s;
    cout << s.longestIncreasingPath(v);
}
