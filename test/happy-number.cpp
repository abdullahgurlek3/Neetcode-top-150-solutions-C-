#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> s;
        while (!(s.count(n) || n == 1))
        {
            s.insert(n);
            int t = 0;
            while (n > 0)
            {
                t += (n % 10) * (n % 10);
                n = (n - n % 10) / 10;
            }
            n = t;
        }
        return n == 1;
    }
};

int main()
{

    Solution s;
    cout << (s.isHappy(111));
}
