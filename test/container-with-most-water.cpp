#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;
        int mx = min(height[i], height[j]) * (j - i);
        while (i < j)
        {
            int local = min(height[i], height[j]) * (j - i);
            if(local>mx) mx=local;
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return mx;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(v);
}
