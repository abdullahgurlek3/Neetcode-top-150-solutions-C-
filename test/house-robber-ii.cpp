#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        vector<int> a = nums;
        vector<int> b = nums;
        a[0] = 0;
        b[b.size() - 1] = 0;

        return max(sub(a), sub(b));
    }

    int sub(vector<int> &nums)
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
    vector<int> v = {8, 2, 8, 9, 2};
    cout << s.rob(v);
}
