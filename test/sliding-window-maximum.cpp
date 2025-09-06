#include "iostream"
#include "helper.h"
#include "unordered_set"

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> v;
        deque<int> d;
        for (int i = 0; i < nums.size(); i++)
        {
            while (d.size() > 0 && nums[d.back()] < nums[i])
            {
                d.pop_back();
            }
            d.push_back(i);
            while (d.size() > 0 && d.front() <= i - k)
            {
                d.pop_front();
            }
            if (i >= k-1)
                v.push_back(nums[d.front()]);
        }
        return v;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, -1};
    print_v(s.maxSlidingWindow(v, 1));
}
