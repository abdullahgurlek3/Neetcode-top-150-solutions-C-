#include "iostream"
#include "helper.h"
#include "map"
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ret;
        ret.push_back(nums);

        int k = nums.size() - 1;
        while (k > 0)
        {
            int i = 0;
            int j = k;
            vector<vector<int>> curr;

            while (i < j)
            {
                for (vector<int> v : ret)
                {
                    vector<int> n(v);
                    swap(n[i], n[j]);
                    curr.push_back(n);
                }
                i++;
            }

            for (vector<int> v : curr)
            {
                ret.push_back(v);
            }
            k--;
        }

        return ret;
    }
};

int main()
{

    Solution s;
    vector<int> st = {1, 2, 3};
    s.permute(st);
}
