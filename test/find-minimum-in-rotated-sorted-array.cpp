#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int i = 0;
        int j = nums.size() - 1;
        while (j - i > 1)
        {
            int m = (i + j) / 2;
            if (nums[i] < nums[m] && nums[m] < nums[j])
            {
                return nums[i];
            }
            else if (nums[m] > nums[i])
            {
                i = m;
            }
            else
            {
                j = m;
            }
            cout << i << " " << j << endl;
        }
        return min(nums[i], nums[j]);
    }
};

int main()
{
    vector<int> v = {11,13,15,17};
    Solution s;
    cout << s.findMin(v);
}
