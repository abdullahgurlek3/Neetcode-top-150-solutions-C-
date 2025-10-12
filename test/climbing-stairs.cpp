#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    map<int,int> cache;
    int climbStairs(int n)
    {
        if(cache.count(n)) return cache[n];
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        int ret=  climbStairs(n - 1) + climbStairs(n - 2);
        cache[n]=ret;
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(3);
}
