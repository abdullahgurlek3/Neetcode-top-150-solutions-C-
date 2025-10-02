#include "iostream"
#include "helper.h"
#include "map"

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> p;
    int size;
    KthLargest(int k, vector<int> &nums)
    {
        for (int n : nums)
        {
            p.push(n);
            if (p.size() > k)
            {
                p.pop();
            }
        }
        size = k;
    }

    int add(int val)
    {
        p.push(val);
        if (p.size() > size)
        {
            p.pop();
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
    vector<int> v = {4, 5, 8, 2};
    KthLargest *obj = new KthLargest(3, v);
    int param_1 = obj->add(3);
}
