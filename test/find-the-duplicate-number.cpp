#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                if (nums[(-nums[i]) - 1] < 0)
                {
                    return (-nums[i]);
                }
                else
                {
                    nums[-nums[i] - 1] = -nums[-nums[i] - 1];
                }
            }
            else
            {
                if (nums[nums[i] - 1] < 0)
                {
                    return nums[i];
                }
                else
                {
                    nums[nums[i] - 1] = -nums[nums[i] - 1];
                }
            }
        }

        return 123;
    }
};

int main()
{
    vector<int> v = {2, 1, 3, 4, 2};
    Solution s;
    cout << s.findDuplicate(v);
}
