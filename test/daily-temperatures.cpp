#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> v;
        vector<int> r(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (v.size() > 0 && temperatures[v.back()] < temperatures[i])
            {
                r[v.back()] = (i - v.back());
                v.pop_back();
            }
            v.push_back(i);
        }
        return r;
    }
};

int main()
{
    vector<int> v = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;
    print_v(s.dailyTemperatures(v));
}
