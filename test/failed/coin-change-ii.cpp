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

        sort(coins.begin(), coins.end(),greater<int>());

        vector<vector<long long>> v(coins.size(), vector<long long>(amount));
        for (int i = 0; i < coins.size(); i++)
        {
            int coin = coins[i];
            if (coin - 1 < amount)
                v[i][coin - 1] = 1;
        }

        for (int i = 0; i < amount; i++)
        {
            for (int k = 0; k < coins.size(); k++)
            {
                int x = i - coins[k];
                if (x >= 0)
                {
                    for (int j = 0; j < coins.size(); j++)
                    {
                        if (coins[j] >= coins[k])
                        {

                            v[k][i] += v[j][x];
                            if (v[k][i] > INT_MAX)
                            {
                                v[k][i] %= INT_MAX;
                            }
                        }else{
                            break;
                        }
                    }
                }
            }
        }
        int total = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            total += v[i][amount - 1];
        }

        return total;
    }
};

int main()
{

    vector<int> v = {1, 101, 102, 103};

    Solution s;
    cout << s.change(100, v);
}
