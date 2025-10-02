#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int n : nums)
        {
            q.push(n);
            if (q.size() > k)
                q.pop();
        }
        return q.top();
    }
};

int main()
{
    vector<int> points = {1, 2, 3, 4, 5, 6, 7};
    Solution s;
    cout << s.findKthLargest(points, 2);
}
