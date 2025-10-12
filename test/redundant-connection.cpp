#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        map<int, vector<int>> m;
        for (vector<int> edge : edges)
        {
            if (!m.count(edge[0]))
            {
                m[edge[0]] = {};
            }
            m[edge[0]].push_back(edge[1]);
        }

        int i = edges.size() - 1;
        while (i >= 0)
        {
            vector<int> b = edges[i];
            i--;
            set<int> visited;
            int ret = deep(b[0], m, visited);
            if (ret > 0)
            {
                set<int> totalret = gettotal(m, b[0], ret, set<int>());

                cout << ret << endl;
                print_s(totalret);
                while (edges.size() > 0)
                {
                    vector<int> c = edges.back();
                    edges.pop_back();
                    if (totalret.count(c[0]) && totalret.count(c[1]))
                        return c;
                }
                break;
            }
        }

        return vector<int>();
    }

    set<int> gettotal(map<int, vector<int>> &m, int start, int end, set<int> total)
    {
                total.insert(start);

        if (start == end)
        {
            return total;
        }
        set<int> r;
        for (int item : m[start])
        {
            for (int x : gettotal(m, item, end, total))
            {
                r.insert(x);
            };
        }
        return r;
    }

    int deep(int start, map<int, vector<int>> &m, set<int> &visited)
    {
        if (visited.count(start))
            return start;
        visited.insert(start);
        for (int item : m[start])
        {
            int ret = deep(item, m, visited);
            if (ret > 0)
                return ret;
        }
        return 0;
    }
};

int main()
{

    Solution s;

    vector<vector<int>> v = {
        {3, 4},
        {1, 2},
        {2, 4},
        {3, 5},
        {2, 5},

    };

    print_v(s.findRedundantConnection(v));
}
