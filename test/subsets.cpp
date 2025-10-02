#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> res;
        vector<vector<int>> ret;
        back(nums, 0, res, ret);
        return ret;
    }

    void back(vector<int> &nums, int start, vector<int> &res, vector<vector<int>> &ret)
    {
        ret.push_back(res);
        for (int i = start; i < nums.size(); i++)
        {
            res.push_back(nums[i]);
            back(nums, i + 1, res, ret);
            res.pop_back();
        }
    }
};

int main()
{

    Solution s;
    vector<int> st = {1, 2, 3};
    s.subsets(st);
}
