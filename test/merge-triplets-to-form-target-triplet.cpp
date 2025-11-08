#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    static bool sf(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0] && a[1] == b[1])
            return a[2] - b[2] < 0;
        if (a[0] == b[0])
        {
            return a[1] - b[1] < 0;
        }
        return a[0] - b[0] < 0;
    }
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        vector<bool> d(triplets.size());
        for (int y = 0; y < triplets.size(); y++)
        {
            if (triplets[y][0] > target[0] || triplets[y][1] > target[1] || triplets[y][2] > target[2])
                d[y] = true;
        }
        vector<int> v = {-1, -1, -1};
        for (int i = 0; i < d.size(); i++)
        {
            if (!d[i])
            {
                v[0] = max(v[0], triplets[i][0]);
                v[1] = max(v[1], triplets[i][1]);
                v[2] = max(v[2], triplets[i][2]);
            }
        }

        return v[0] == target[0] && v[1] == target[1] && v[2] == target[2];
    }
};

int main()
{

    vector<vector<int>> triplets = {
        {2, 5, 3},
        {2, 3, 4},
        {1, 2, 5},
        {5, 2, 3},
    };

    vector<int> target = {5, 5, 5};

    Solution s;
    cout << s.mergeTriplets(triplets, target);
}
