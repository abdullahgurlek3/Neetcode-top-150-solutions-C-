#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        map<char, int> m;
        for (char task : tasks)
        {
            m[task]++;
        }
        priority_queue<int> pq;
        for (const auto &i : m)
        {
            pq.push(i.second);
        }
        int total = 0;
        while (pq.size() > 0)
        {
            int i = 0;
            vector<int> v;
            while (pq.size() > 0 && i <= n)
            {
                int last = pq.top();
                v.push_back(last);
                pq.pop();
                i++;
            }
            for (int x : v)
            {
                if (x > 1)
                {
                    pq.push(x - 1);
                }
            }
            total += n + 1;
            if (pq.size() == 0 && v.size() < n + 1)
            {
                total -= n + 1 - v.size();
            }
        }

        return total;
    }
};

int main()
{
    vector<char> points = {'A', 'C', 'A', 'B', 'D', 'B'};
    Solution s;
    cout << s.leastInterval(points, 1);
}
