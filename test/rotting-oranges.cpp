#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        deque<pair<int, int>> q;
        for (int y = 0; y < grid.size(); y++)
        {
            for (int x = 0; x < grid[y].size(); x++)
            {
                if (grid[y][x] == 2)
                {
                    q.push_back({y, x});
                }
            }
        }

        int step = 0;
        while (q.size() > 0)
        {
            deque<pair<int, int>> n;
            while (q.size() > 0)
            {
                pair<int, int> f = q.front();
                q.pop_front();

                if (f.first + 1 < grid.size() && grid[f.first + 1][f.second] == 1)
                {
                    grid[f.first + 1][f.second] = 2;
                    n.push_back({f.first + 1, f.second});
                }
                if (f.first > 0 && grid[f.first - 1][f.second] == 1)
                {
                    grid[f.first - 1][f.second] = 2;
                    n.push_back({f.first - 1, f.second});
                }
                if (f.second + 1 < grid[0].size() && grid[f.first][f.second + 1] == 1)
                {
                    grid[f.first][f.second + 1] = 2;
                    n.push_back({f.first, f.second + 1});
                }
                if (f.second > 0 && grid[f.first][f.second - 1] == 1)
                {
                    grid[f.first][f.second - 1] = 2;
                    n.push_back({f.first, f.second - 1});
                }
            }
            q = n;
            if (q.size() > 0)
                step++;
        }

        for (int y = 0; y < grid.size(); y++)
        {
            for (int x = 0; x < grid[y].size(); x++)
            {
                if (grid[y][x] == 1)
                {
                    return -1;
                }
            }
        }
        return step;
    }
};

int main()
{

    vector<vector<int>> v = {{0}};

    Solution s;
    cout << s.orangesRotting(v);
}
