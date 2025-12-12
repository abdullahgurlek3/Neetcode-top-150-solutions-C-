#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        sort(coins.begin(), coins.end(), greater<int>());

        int ret = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            ret += dfs(coins, i, coins[i], amount);
        }
        return ret;
    }

    int dfs(vector<int> &coins, int index, int total, int amount)
    {
        if (index >= coins.size())
            return 0;
        if (total > amount)
            return 0;
        if (total == amount)
            return 1;

        int ret = dfs(coins, index, total + coins[index], amount);
        int ret2 = dfs(coins, index + 1, total + coins[index], amount);
        return ret + ret2;
    }
};

int main()
{

    vector<int> v = {1,2, 5};

    Solution s;
    cout << s.change(5, v);
}
