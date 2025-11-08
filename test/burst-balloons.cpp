#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        deep(nums);
    }

    void deep(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> n(i);
        }
    }
};

int main()
{

    vector<int> v = {3, 1, 5, 8};

    Solution s;
    cout << s.maxCoins(v);
}
