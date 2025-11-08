#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        return maxProductSub(nums, 0, nums.size() - 1);
    };

    int maxProductSub(vector<int> &nums, int start, int end)
    {
        if (end < start)
            return 0;
        if (end == start)
            return nums[start];
        int t = 1;
        for (int i = start; i <= end; i++)
        {
            if (nums[i] == 0)
            {
                return max(0, max(maxProductSub(nums, start, i - 1), maxProductSub(nums, i + 1, end)));
            }
            t *= nums[i];
        }
        if (t > 0)
            return t;
        int i = start;
        int l = 1;
        while (nums[i] > 0)
        {
            l *= nums[i];
            i++;
        }
        l *= nums[i];

        int j = end;
        int r = 1;
        while (nums[j] > 0)
        {
            r *= nums[j];
            j--;
        }
        if(l==0) throw "dsf";
        r *= nums[j];
        return max(t / r, t / l);
    };
};

int main()
{
    Solution s;
    vector<int> v = {1, 0, -1, 2, 3, -5, -2};
    cout << s.maxProduct(v) << endl;
}
