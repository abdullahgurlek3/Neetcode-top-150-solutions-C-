#include "iostream"
#include "helper.h"
#include "map"

// class Solution
// {
// public:
//     map<int, int> cache;
//     double myPow(double x, int n)
//     {
//         if (cache.count(n))
//             return cache[n];
//         if (n < 0)
//             return 1 / myPow(x, -n);
//         if (n == 0)
//             return 1;
//         if (n == 1)
//             return x;
//         int ret = x * myPow(x, n - 1);
//         cache[n] = ret;
//         return ret;
//     }
// };

class Solution
{
public:
    map<int, double> cache;
    double myPow(double x, int n)
    {
        if (cache.count(n))
            return cache[n];

        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;
        if (n == 0)
            return 1;

        double ret;
        if (n % 2 == 0)
            ret = myPow(x, n / 2) * myPow(x, n / 2);
        else
            ret = myPow(x, n / 2) * (n > 0 ? x : 1/x) * myPow(x, n / 2);

        cache[n] = ret;
        return ret;
    }
};

int main()
{
    Solution s;
    cout << ((s.myPow(2, 10)));
}
