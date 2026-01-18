
#include "iostream"
#include "helper.h"
#include "map"
/*
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> d(n);
        for (int i = 0; i < n; i++)
        {
            d[i] = INT_MAX;
        }

        d[k - 1] = 0;

        for (int i = 0; i < n; i++)
        {
            for (vector<int> time : times)
            {
                int from = time[0] - 1;
                int to = time[1] - 1;
                if (d[from] != INT_MAX)
                {
                    d[to] = min(d[to], d[from] + time[2]);
                }
            }
        }
        int mx = d[0];
        for (int x : d)
        {
            if (x == INT_MAX)
                return -1;
            if (x > mx)
                mx = x;
        }

        return mx;
    }
};


class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        map<int, vector<pair<int, int>>> m;
        for (vector<int> time : times)
        {
            if (!m.count(time[0] - 1))
                m[time[0] - 1] = {};
            m[time[0] - 1].push_back({time[1] - 1, time[2]});
        }

        deque<int> q;
        q.push_back(k);

        vector<int> res(n, -1);
        res[k - 1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1});

        set<int> visited;

        while (pq.size() > 0)
        {
            pair<int, int> parent = pq.top();
            pq.pop();

            cout << parent.second << endl;
            if (visited.count(parent.second))
                continue;

            for (pair<int, int> child : m[parent.second])
            {
                if (res[child.second] == -1)
                    res[child.second] = child.first + parent.first;
                else
                    res[child.second] = max(res[child.second], child.first + parent.first);

                pq.push({child.first - parent.first, child.second});
            }
        }

        print_v(res);
        return 1;
    };
};
 */

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> v(n + 1, INT_MAX);
        v[k] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < times.size(); j++)
            {
                vector<int> current = times[j];
                int source = current[0];
                int target = current[1];
                int w = current[2];
                if (v[source] != INT_MAX && v[source] + w < v[target])
                {
                    v[target] = v[source] + w;
                }
            }
        }
        int mn = 0;

        for (int i = 1; i < n + 1; i++)
        {

            mn = max(mn, v[i]);
        }

        return mn == INT_MAX ? -1 : mn;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> v = {
        {1, 2, 1},
    };

    cout << (s.networkDelayTime(v, 2, 1));
}
