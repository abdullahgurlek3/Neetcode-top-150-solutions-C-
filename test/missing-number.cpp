#include "iostream"
#include "helper.h"
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int s = 0;
        for (int i = 0; i <= nums.size(); i++)
        {
            s ^= i;
        }
        for (int c : nums)
            s ^= c;

        return s;
    }
};

int main()
{
    vector<int> v = {3, 0, 1};
    Solution s;
    cout << (s.missingNumber(v));
}
