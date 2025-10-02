#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        map<char, int> m;
        for (char c : tasks)
        {
            m[c]++;
        }
        int count = 0;
        while (m.size() > 0)
        {
            count += n + 1;
            vector<int> deleted;
            int limit=0;
            for (const auto a : m)
            {
                if (a.second > 0)
                {
                    m[a.first]--;
                    if (m[a.first] == 0)
                    {
                        deleted.push_back(a.first);
                    }
                }
                limit++;
                if (limit==n)
                {
                    break;
                }
                
            }
            for (int d : deleted)
            {
                m.erase(d);
            }
        }
        return count-1;
    }
};

int main()
{
    vector<char> points = {'A', 'A', 'B', 'B'};
    Solution s;
    cout << s.leastInterval(points, 2);
}
