#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        sort(intervals.begin(), intervals.end());
        vector<int> ret;

        print_matrix(intervals);
        for (int &q : queries)
        {
            int i = 0;
            int m = -1;
            while (i < intervals.size())
            {
                if (intervals[i][0] <= q && intervals[i][1] >= q)
                {
                    cout << q << " " << i << endl;
                    if (m == -1)
                        m = i;
                    else if (intervals[m][1] - intervals[m][0] > intervals[i][1] - intervals[i][0])
                        m = i;
                    /* code */
                }

                i++;
            }
            if (m == -1)
                ret.push_back(-1);
            else
                ret.push_back(intervals[m][1] - intervals[m][0] + 1);
        }

        return ret;
    }
};

int main()
{

    vector<vector<int>> l = {{2, 3}, {2, 5}, {1, 8}, {20, 25}};
    vector<int> v = {2, 19, 5, 22};
    Solution s;
    print_v(s.minInterval(l, v));
}
