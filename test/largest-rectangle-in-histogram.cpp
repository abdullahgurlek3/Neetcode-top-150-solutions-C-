#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        deque<pair<int, int>> q;
        int i = 0;
        int mx = 0;

        for (int h : heights)
        {

            pair<int, int> l = {i, h};
            while (q.size() > 0 && q.back().second > h)
            {
                pair<int, int> last = q.back();
                int x = (i - last.first) * last.second;
                if (x > mx)
                    mx = x;
                l = last;
                q.pop_back();
            }

            if (h > 0)
            {
                l.second = h;
                q.push_back(l);
            }
            i++;
        }

        return mx;
    }
};

int main()
{
    vector<int> v = {6, 5, 7};
    Solution s;

    cout << (s.largestRectangleArea(v));
}
