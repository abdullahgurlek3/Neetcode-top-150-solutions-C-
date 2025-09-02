#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l[height.size()];
        int r[height.size()];
        int mx = height[0];
        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] > mx)
                mx = height[i];
            l[i] = mx;
        }
        r[height.size() - 1] = height[height.size() - 1];
        mx = height[height.size() - 1];
        for (int i = height.size() - 1; i >= 0; i--)
        {
            if (height[i] > mx)
            {
                mx = height[i];
            }
            r[i] = mx;
        }
        int ret = 0;
        for (int i = 0; i < height.size(); i++)
        {
            ret += min(l[i], r[i]) - height[i];
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(v);
}
