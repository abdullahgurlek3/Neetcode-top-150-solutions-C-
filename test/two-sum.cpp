#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            int c = nums[i];
            if (m.count(target - c) > 0)
            {
                vector<int> v;
                v.push_back(m[target - c]);
                v.push_back(i);
                return v;
            }
            m[c] = i;
        }
        vector<int> v = {-1, -1};

        return v;
    }
};

int main()
{
    Solution s;
    vector<int> v = {2, 7, 11, 15};
    s.twoSum(v, 19);
}
