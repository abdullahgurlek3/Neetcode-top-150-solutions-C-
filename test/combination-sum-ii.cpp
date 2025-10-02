#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
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
        int last;
        for (int i = start; i < candidates.size(); i++)
        {
            if (last == candidates[i])
            {
                continue;
            }

            total += candidates[i];
            v.push_back(candidates[i]);
            back(candidates, target, total, v, i + 1, ret);
            total -= candidates[i];
            last = v.back();
            v.pop_back();
        }
    }
};

int main()
{

    Solution s;
    vector<int> st = {10, 1, 2, 7, 6, 1, 5};
    s.combinationSum2(st, 8);
}
