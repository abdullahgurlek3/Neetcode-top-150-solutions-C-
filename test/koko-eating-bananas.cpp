#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        sort(piles.begin(), piles.end());

        int i = 1;
        int j = piles[piles.size() - 1];
        while (i < j)
        {
            int m = (i + j) / 2;
            int total = 0;
            for (int c : piles)
            {
                if (c % m == 0)
                {
                    total += (c / m);
                }
                else
                {
                    total += (c / m) + 1;
                }
            }
            if (total <= h)
            {
                j = m;
            }
            else
            {
                i = m + 1;
            }
        }
        return i;
    }
};

int main()
{
    Solution s;
    vector<int> v = {3, 6, 7, 11};
    cout << (s.minEatingSpeed(v, 8));
}
