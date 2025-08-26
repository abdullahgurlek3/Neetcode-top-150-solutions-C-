#include "iostream"
#include "helper.h"
#include "map"
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int l[nums.size()];
        int r[nums.size()];

        l[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            l[i] = l[i - 1] * nums[i-1];
        }

        r[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            r[i] = r[i + 1] * nums[i+1];
        }

        vector<int> v;

        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back(l[i] * r[i]);
        }

        return v;
    }
};

int main()
{
    Solution s;
    vector<int> v = {2, 7, 11, 15};
    print_v(s.productExceptSelf(v));
}
