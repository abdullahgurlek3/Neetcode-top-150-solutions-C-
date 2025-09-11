#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int i = 0;
        int j = nums.size() - 1;
        while (j - i > 1)
        {
            int m = (i + j) / 2;
            if (target == nums[m])
                return m;
            if (nums[m] > nums[i] && target <= nums[m] && target >= nums[i])
            {
                j = m;
            }
            else if (nums[j] > nums[m] && target <= nums[j] && target >= nums[m])
            {
                i = m + 1;
            }
            else
            {
                if (nums[m] > nums[i])
                {
                    i = m + 1;
                }
                else
                {
                    j = m;
                }
            }
        }
        if(nums[i]==target) return i;
        if(nums[j]==target) return j;
        
        return -1;
    }
};

int main()
{
    vector<int> v = {4,5,6,7,0,1,2};
    Solution s;
    cout << s.search(v, 0);
}
