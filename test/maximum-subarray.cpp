#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int s = nums[0];
        int m = s;
        for (int i = 1; i < nums.size(); i++)
        {
            if (s < 0)
            {
                s = nums[i];
            }
            else
            {
                s += nums[i];
            }

            if (s > m)
            {
                m = s;
            }
        }
        return m;
    }
};

int main()
{

    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    cout << s.maxSubArray(v);
}
