#include "iostream"
#include "helper.h"

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int s = nums[0];
        for (int i = 1; i < nums.size(); i++)
            s ^= nums[i];
        return s;
    }
};

int main()
{
    vector<int> v = {1923,1,1, 2, 3, 2, 3};
    Solution s;
    cout << s.singleNumber(v);
}
