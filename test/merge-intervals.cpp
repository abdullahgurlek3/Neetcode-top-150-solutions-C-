#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= ret.back()[1] && intervals[i][0] >= ret.back()[0])
            {
            }
            else if (intervals[i][0] <= ret.back()[1])
            {
                ret.back()[1] = intervals[i][1];
            }
            else
            {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};

int main()
{

    vector<vector<int>> l = {{1, 3}, {2, 9}, {10, 13}};
    Solution s;
    print_matrix(s.merge(l));
}
