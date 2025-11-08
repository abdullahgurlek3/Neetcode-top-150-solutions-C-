#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        deep(prices, 0, 0);
    }
    void deep(vector<int> &prices, int start, int profit)
    {
        
    }
};

int main()
{

    vector<int> v = {1, 23, 3, 4};

    Solution s;
    cout << s.maxProfit(v);
}
