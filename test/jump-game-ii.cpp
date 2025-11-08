#include "iostream"
#include "helper.h"
#include "map"
/*
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        map<int, int> cache;
        return deep(nums, 0, 0, cache);
    }
    int deep(vector<int> &nums, int index, int level, map<int, int> &cache)
    {
        if (cache.count(index))
        {
            return cache[index];
        }

        if (index >= nums.size() - 1)
            return 0;
        int step = nums[index];
        int ret = -1;
        while (step > 0)
        {
            int curr;
            if (cache.count(index + step))
            {
                curr = cache[index + step];
            }
            else
            {
                curr = deep(nums, index + step, level, cache);
            }
            if (curr >= 0 && (ret == -1 || curr + 1 < ret))
            {
                ret = curr + 1;
            }
            step--;
        }
        cache[index] = ret;
        return ret;
    }
}; */

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        vector<int> ar(nums.size(), INT_MAX);
        ar[0] = 0;
        for (int i = 0; i < ar.size(); i++)
        {
            if (ar[i] != INT_MAX)
            {
                for (int j = 0; j < nums[i]; j++)
                {
                    if (i + j + 1 < ar.size())
                    {
                        ar[i + j + 1] = min(ar[i + j + 1], ar[i] + 1);
                    }
                }
            }
        }
        return ar[ar.size() - 1];
    }
};

int main()
{

    vector<int> v = {5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5};
    Solution s;
    cout << s.jump(v);
}
