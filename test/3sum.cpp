#include "iostream"
#include "helper.h"
#include "map"
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if(nums[i] > 0) break;

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                
                int t = nums[i] + nums[j] + nums[k];
                if (t > 0)
                {
                    k--;
                }
                else if (t == 0)
                {
                    v.push_back({nums[i],nums[j],nums[k]});
                    

                    while (j < k && nums[j]==nums[j+1])
                    {
                        j++;
                    }

                    while ( j < k && nums[k]==nums[k-1])
                    {
                        k--;
                    }

                    
                    j++;
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return v;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-1,0,1,0};
    s.threeSum(v);
}
