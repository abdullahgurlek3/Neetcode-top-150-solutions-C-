#include "iostream"
#include "helper.h"

class Solution
{
public:
    int reverseBits(int n)
    {
        int mask = 1 << 30;
        int ret = 0;
        n = n >> 1;
        while (n > 0)
        {
            int bt = n & 1;
            if (bt)
                ret = ret | mask;
            mask = mask >> 1;
            n = n >> 1;
        }

        return ret;
    }
};

int main()
{

    Solution s;
    cout << (s.reverseBits(2147483644));
}
