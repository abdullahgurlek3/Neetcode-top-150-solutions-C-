#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        nums[nums.size() - 3] += nums[nums.size() - 1];
        int i = nums.size() - 4;
        while (i >= 0)
        {
            nums[i] += max(nums[i + 2], nums[i + 3]);
            i--;
        }
        return max(nums[0], nums[1]);
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 3, 1};
    cout << s.rob(v);
}
