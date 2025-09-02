#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int t = 0;
        int m = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            t += prices[i] - prices[i - 1];
            if (t < 0)
                t = 0;

            if (t > m)
                m = t;
        }
        if (t > m)
            m = t;
        return m;
    }
};

int main()
{
    Solution s;
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(v);
}
