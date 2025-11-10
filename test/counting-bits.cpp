#include "iostream"
#include "helper.h"
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> v;

        for (int i = 0; i <= n; i++)
        {
            int count = 0;
            int k=i;
            while (k > 0)
            {
                count += k & 1;
                k = k >> 1;
            }
            v.push_back(count);
        }

        return v;
    }
};

int main()
{

    Solution s;
    print_v(s.countBits(5));
}
