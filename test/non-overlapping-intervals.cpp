#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        int count = 1;
        vector<int> m = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= m[1])
            {
                count++;
                m = intervals[i];
            }
            else
            {
                m[0] = min(m[0], intervals[i][0]);
                m[1] = min(m[1], intervals[i][1]);
            }
        }
        return intervals.size() - count;
    }
};

int main()
{

    vector<vector<int>> l = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
    Solution s;
    cout << (s.eraseOverlapIntervals(l));
}
