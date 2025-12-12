#include "iostream"
#include "helper.h"

class Solution
{
public:
    int reverse(int x)
    {
        long t = 0;

        while (x != 0)
        {
            int k = x % 10;
            t = (t * 10) + k;
            if (t > INT_MAX || t < INT_MIN)
            {
                return 0;
            }

            x = (x - k) / 10;
        }

        return t;
    }
};

int main()
{
    Solution s;
    cout << (s.reverse(-1234));
}
