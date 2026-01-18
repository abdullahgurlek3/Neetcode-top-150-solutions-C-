#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                int m = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                
            }
            
        }
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
