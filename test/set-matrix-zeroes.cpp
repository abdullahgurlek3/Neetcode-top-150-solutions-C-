#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> xs;
        unordered_set<int> ys;

        for (int y = 0; y < matrix.size(); y++)
        {
            for (int x = 0; x < matrix[0].size(); x++)
            {
                
                if (matrix[y][x] == 0)
                {
                    ys.insert(y);
                    xs.insert(x);

                    int a = y;
                    while (a >= 0)
                    {
                        matrix[a][x] = 0;
                        a--;
                    }
                    int b = x;
                    while (b >= 0)
                    {
                        matrix[y][b] = 0;
                        b--;
                    }
                }
                for (int c : ys)
                {
                    if (y == c)
                    {
                        matrix[y][x] = 0;
                    }
                }
                for (int c : xs)
                {
                    if (x == c)
                    {
                        matrix[y][x] = 0;
                    }
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> l =
        {
            {1, 0, 1},
            {1, 1, 1}};
    Solution s;
    s.setZeroes(l);
}
