#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return deep(nums, target, 0, 0);
    }
    int deep(vector<int> &nums, int target, int total, int start)
    {
        if (start == nums.size())
        {
            if (target == total)
                return 1;
            else
                return 0;
        }
        int l = deep(nums, target, total - nums[start], start + 1);
        int r = deep(nums, target, total + nums[start], start + 1);

        return l + r;
    }
};

int main()
{

    vector<int> v = {1, 1, 1, 1, 1};

    Solution s;
    cout << s.findTargetSumWays(v, 3);
}
