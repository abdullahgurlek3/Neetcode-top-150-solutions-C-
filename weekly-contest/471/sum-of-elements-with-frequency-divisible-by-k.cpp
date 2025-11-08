#include "iostream"
#include "../../test/helper.h"
#include "map"

class Solution
{
public:
    int sumDivisibleByK(vector<int> &nums, int k)
    {
        map<int, int> m;
        for (int x : nums)
        {
            m[x]++;
        }
        int total = 0;
        for (const auto item : m)
        {
            if (item.second % k == 0)
            {
                total += item.second *item.first;
            }
        }
        return total;
    }
};

int main()
{

    Solution s;
    vector<int> st = {0, 1, 0, 3, 2, 3};
    cout << s.sumDivisibleByK(st, 3);
}
