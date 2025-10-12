#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {

        int i = cost.size() - 3;
        while (i >= 0)
        {
            cost[i] += min(cost[i + 1], cost[i + 2]);
            
            i--;
        }
        return min(cost[0], cost[1]);
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << s.minCostClimbingStairs(v);
}
