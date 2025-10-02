#include "iostream"
#include "helper.h"
#include "map"
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> v;

        deque<pair<int, int>> q2;
        for (int x = 0; x < heights[0].size(); x++)
        {
            q2.push_back({heights.size() - 1, x});
        }

        for (int y = 0; y < heights.size()-1; y++)
        {
            q2.push_back({y, heights[0].size() - 1});
        }

        deque<pair<int, int>> q;
        for (int x = 0; x < heights[0].size(); x++)
        {
            q.push_back({0, x});
        }

        for (int y = 1; y < heights.size(); y++)
        {
            q.push_back({y, 0});
        }

        vector<vector<int>> atlantic = deep(heights, q2);
        vector<vector<int>> pacific = deep(heights, q);

        for (int y = 0; y < heights.size(); y++)
        {
            for (int x = 0; x < heights[0].size(); x++)
            {
                if (pacific[y][x] == -1 && atlantic[y][x] == -1)
                {
                    v.push_back({y, x});
                }
            }
        }

        return v;
    }
    vector<vector<int>> deep(vector<vector<int>> &heights, deque<pair<int, int>> &q)
    {
        vector<vector<int>> cp = heights;
        while (q.size() > 0)
        {
            pair<int, int> f = q.front();
            q.pop_front();

            if (cp[f.first][f.second] == -1)
            {
                continue;
            }

            cp[f.first][f.second] = -1;

            if (f.first + 1 < heights.size() && cp[f.first + 1][f.second] >= heights[f.first][f.second])
                q.push_back({f.first + 1, f.second});
            if (f.second + 1 < heights[0].size() && cp[f.first][f.second + 1] >= heights[f.first][f.second])
                q.push_back({f.first, f.second + 1});
            if (f.first > 0 && cp[f.first - 1][f.second] >= heights[f.first][f.second])
            {
                q.push_back({f.first - 1, f.second});
            }
            if (f.second > 0 && cp[f.first][f.second - 1] >= heights[f.first][f.second])
                q.push_back({f.first, f.second - 1});
        }
        return cp;
    }
};

int main()
{

    vector<vector<int>> v = {
        {2, 1},
        {1, 2},
    };

    Solution s;
    vector<vector<int>> res = s.pacificAtlantic(v);
    cout << res.size();
}
