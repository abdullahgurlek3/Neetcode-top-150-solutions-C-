#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    static bool sf(vector<int> a, vector<int> b)
    {
        return abs(a[0] - b[0]) > 0;
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), sf);
        int ret = 0;
        for (int i = 1; i < points.size(); i++)
        {
            ret += abs(points[i][1] - points[i - 1][1]) + abs(points[i][0] - points[i - 1][0]);
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> v = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0},
    };

    Solution s;
    cout << s.minCostConnectPoints(v);
}
