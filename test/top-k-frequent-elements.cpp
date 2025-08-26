#include "iostream"
#include "helper.h"
#include "map"

struct Node
{
    int val;
    int freq;
};

class Solution
{
public:
    static bool sb(Node a, Node b)
    {
        return a.freq - b.freq > 0;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> b;
        int ar[20000] = {};
        for (int v : nums)
        {
            ar[v + 10000]++;
        }
        vector<Node> bucket;
        for (int i = 0; i < 20000; i++)
        {
            if (ar[i] > 0)
            {
                bucket.push_back(Node{val : i - 10000, freq : ar[i]});
            }
        }

        sort(bucket.begin(), bucket.end(), sb);

        int i = 0;
        while (k > 0)
        {
            b.push_back(bucket[i].val);
            i++;
            k--;
        }

        return b;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-1, -1 , -1, 1, 2, 2, 3, 4, 5};
    print_v(s.topKFrequent(v, 2));
}
