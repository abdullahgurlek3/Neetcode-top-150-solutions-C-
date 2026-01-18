#include "iostream"
#include "helper.h"
#include "map"
/*
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        unordered_map<int, int> cache;
        int ret =  max(deep(prices, 0, -1, 0, cache),
                   deep(prices, 0, -2, 0, cache));

        print_map(cache);
        return ret;
    }
    int deep(vector<int> &prices, int index, int s, int total, unordered_map<int, int> &cache)
    {
        if(total<0) return 0;
        if (cache.count(index))
            return cache[index];
        if (index == prices.size())
            return total;

        if (s == -1)
            s = index;

        if (s == -2)
            s = -1;

        int l = deep(prices, index + 1, s, total, cache);
        int r = deep(prices, index + 1, -2, total + (s >= 0 ? prices[index] - prices[s] : 0), cache);
        int ret = max(l, r);
        return ret;
    }
};
 */

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i = 0;
        int mn = prices[0];
        int mx = 0;
        int start = 0;
        int total=0;
        while (i < prices.size())
        {
            while (i < prices.size() && (prices[i] >= mn || i > 0 && prices[i] > prices[i - 1]))
            {
                mx = max(mx, prices[i] - prices[start]);
                i++;
            }
            total+=mx;
            mn = prices[i];
            start = i;

            i++;
        }
        return total;
    }
};

int main()
{

    vector<int> v = {4, 3, 2, 10, 11, 0, 11};

    Solution s;
    cout << s.maxProfit(v);
}
