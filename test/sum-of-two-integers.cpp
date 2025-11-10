#include "iostream"
#include "helper.h"

class Solution
{
public:
    int getSum(int a, int b)
    {
        int r = 0;
        int mask = 1;
        int t = 0;
        for (int k = 0; k < 32; k++)
        {
            int c = (a & 1) ^ (b & 1) ^ r;
            if (r)
            {
                r = (a & 1) | (b & 1);
            }
            else
            {
                r = (a & 1) & (b & 1);
            }
            if (c)
                t = t | mask;
            a = a >> 1;
            b = b >> 1;
            mask = mask << 1;
        }
        if (r > 0)
            t = t | mask;
        return t;
    }
};

int main()
{
    Solution s;
    cout << (s.getSum(10, 11));
}
