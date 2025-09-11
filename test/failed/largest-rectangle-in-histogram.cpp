#include "iostream"
#include "helper.h"
#include "map"

struct Pair
{
    int start;
    int mn;
};

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        vector<Pair> q;
        int mx = 0;
        for (int i = 0; i < heights.size(); i++)
        {

            for (int j = q.size() - 1; j >= 0; j--)
            {
                if (q[j].mn >= heights[i])
                {
                    q[j].mn = heights[i];
                    if (q[j].mn * (i - q[j].start + 1) > mx)
                    {
                        mx = q[j].mn * (i - q[j].start + 1);
                    }
                }
                else
                {
                    if (q[j].mn * (i - q[j].start + 1) > mx)
                    {
                        mx = q[j].mn * (i - q[j].start + 1);
                    }
                    break;
                }
            }

            if (i == 0 || heights[i] > heights[i - 1])
            {
                q.push_back(Pair{mn : heights[i], start : i});
            }
            if (heights[i] > mx)
                mx = heights[i];
        }
        return mx;
    }
};

int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3};
    Solution s;

    cout << (s.largestRectangleArea(v));
}
