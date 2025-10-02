#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {

        vector<vector<bool>> visited(grid.size());
        for (int i = 0; i < grid.size(); i++)
        {
            visited[i] = vector<bool>(grid[0].size());
        }

        int mx = 0;
        for (int y = 0; y < grid.size(); y++)
        {
            for (int x = 0; x < grid[0].size(); x++)
            {
                if (grid[y][x] == 1 && !visited[y][x])
                {
                    int tmp=0;
                    int l = dfs(grid, y, x, visited, &tmp);
                    if (l > mx)
                        mx = l;
                }
            }
        }

        return mx;
    }
    int dfs(vector<vector<int>> &grid, int y, int x, vector<vector<bool>> &visited, int *total)
    {
        if (y == grid.size() || x == grid[0].size() || y < 0 || x < 0)
            return *total;
        if (grid[y][x] == 0)
            return *total;
        if (visited[y][x])
            return *total;

        visited[y][x] = true;
        (*total)++;
        int a = dfs(grid, y + 1, x, visited, total );
        int b = dfs(grid, y, x + 1, visited, total );
        int c = dfs(grid, y - 1, x, visited, total );
        int d = dfs(grid, y, x - 1, visited, total );

        return max(max(a, b), max(c, d));
    }
};

int main()
{

    Solution s;
    vector<vector<int>> v = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, 
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << s.maxAreaOfIsland(v);
}
