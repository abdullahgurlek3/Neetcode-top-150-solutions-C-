#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int calc(vector<int> &piles, int start)
    {
        int t = 0;
        for (int j = start; j < piles.size(); j++)
        {
            t += (piles[j] / piles[start]) + ((piles[j] % piles[start]) == 0 ? 0 : 1);
        }
        return t + start;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        sort(piles.begin(), piles.end());
        print_v(piles);
        int i = 0;
        while (i < piles.size())
        {
            int l = calc(piles, i);
            if (l == h)
            {
                return piles[i];
            }
            cout << piles[i] << " " << l << " " << " " << endl;

            if (l < h)
                break;
            i++;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v = {3, 6, 7, 11};
    cout << (s.minEatingSpeed(v, 8));
}
