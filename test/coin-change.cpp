#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount==0)return 0;
        
        vector<uint32_t> v(amount + 1);

        for (int c : coins)
        {
            if (amount<c) continue;
            v[c] = 1;
        }

        for (int i = 0; i < amount + 1; i++)
        {
            if (v[i])
                for (int c : coins)
                {
                    if (long(i)+long(c)>INT_MAX|| i  + c > amount)
                        continue;

                    if (v[i + c])
                    {
                        v[i + c] = min(v[i + c], v[i] + 1);
                    }
                    else
                    {
                        v[i + c] = v[i] + 1;
                    }
                }
        }
        return v[amount]==0?-1:v[amount];
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 5};
    cout << s.coinChange(v, 11) << endl;
}
