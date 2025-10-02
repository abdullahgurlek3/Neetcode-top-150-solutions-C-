#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<bool>> visited(grid.size());
        for (int i = 0; i < grid.size(); i++)
        {
            visited[i] = vector<bool>(grid[0].size());
        }

        int count = 0;
        for (int y = 0; y < grid.size(); y++)
        {
            for (int x = 0; x < grid[0].size(); x++)
            {
                if (grid[y][x] == '1' && !visited[y][x])
                {
                    count++;
                    dfs(grid, y, x, visited);
                }
            }
        }

        return count;
    }
    void dfs(vector<vector<char>> &grid, int y, int x, vector<vector<bool>> &visited)
    {
        if (y == grid.size() || x == grid[0].size() || y < 0 || x < 0)
            return;
        if (grid[y][x]=='0')
            return;
        if (visited[y][x])
            return;

        visited[y][x] = true;
        dfs(grid, y + 1, x, visited);
        dfs(grid, y, x + 1, visited);
        dfs(grid, y - 1, x, visited);
        dfs(grid, y, x - 1, visited);
    }
};

int main()
{

    Solution s;
    vector<vector<char>> v = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '0', '0', '0', '0'},
        {'0', '0', '1', '0', '1'}};
    cout << s.numIslands(v);
}
