#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> v(nums.size(), 1);
        v[nums.size() - 1] = 1;
        int j = nums.size() - 1;
        while (j >= 0)
        {
            int k = j - 1;
            while (k >= 0)
            {
                if (nums[k] < nums[j] && v[k] < v[j] + 1)
                {
                    v[k] = v[j] + 1;
                }
                k--;
            }
            j--;
        }
        int mx = v[0];
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] > mx)
                mx = v[i];
        }

        return mx;
    }
};

int main()
{

    Solution s;
    vector<int> st = {0, 1, 0, 3, 2, 3};
    cout << s.lengthOfLIS(st);
}
