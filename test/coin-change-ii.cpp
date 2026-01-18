#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;
        sort(coins.begin(), coins.end(), greater<int>());
        vector<vector<int>> cache(amount + 1, vector<int>(coins.size(), -1));
        return dfs(coins, 0, amount, cache);
    }

    int dfs(vector<int> &coins, int index, int amount, vector<vector<int>> &cache)
    {
        if (index >= coins.size())
        {
            return 0;
        }

        if (amount < 0)
        {
            return 0;
        }

        if (0 == amount)
        {
            return 1;
        }
        if (cache[amount][index] > -1)
            return cache[amount][index];

        if (amount >= 0)
        {
            int ret = dfs(coins, index + 1, amount, cache);
            ret += dfs(coins, index, amount - coins[index], cache);
            cache[amount][index] = ret;
            return ret;
        }
        cache[amount][index] = 0;

        return 0;
    }
};

int main()
{
    vector<int> v = {2, 1};

    Solution s;
    cout << s.change(12, v);
}
