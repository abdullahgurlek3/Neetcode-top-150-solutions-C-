#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        vector<vector<int>> ret;

        sort(candidates.begin(), candidates.end());
        back(candidates, target, 0, v, 0, ret);
        return ret;
    }

    void back(vector<int> &candidates, int target, int total, vector<int> &v, int start, vector<vector<int>> &ret)
    {
        if (total > target)
        {
            return;
        }
        if (total == target)
        {
            ret.push_back(v);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            total += candidates[i];
            v.push_back(candidates[i]);
            back(candidates, target, total, v, i, ret);
            total -= candidates[i];
            v.pop_back();
        }
    }
};
int main()
{

    Solution s;
    vector<int> st = {2, 3, 6, 7};
    s.combinationSum(st, 7);
}
