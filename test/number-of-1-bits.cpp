#include "iostream"
#include "helper.h"

class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }
};

int main()
{

    Solution s;
    cout << s.hammingWeight(121241243);
}
