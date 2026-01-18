#include "iostream"
#include "helper.h"
#include "map"
/*
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> m;
        for (vector<int> &e : edges)
        {
            if (!m.count(e[0]))
                m[e[0]] = vector<int>();

            m[e[0]].push_back(e[1]);

            if (!m.count(e[1]))
                m[e[1]] = vector<int>();

            m[e[1]].push_back(e[0]);
        }
        for (int i = edges.size() - 1; i >= 0; i--)
        {
            unordered_set<int> visited;
            if (deep(m, edges[i][0], edges[i][1], visited, edges[i][0]))
                return edges[i];
        }
        return vector<int>();
    }

    bool deep(unordered_map<int, vector<int>> &m, int prev, int cur, unordered_set<int> &visited, int start)
    {
        if (m.count(cur) == 0)
            return false;
        if (visited.count(cur))
            return visited.count(start)>0;
        visited.insert(cur);
        vector<int> v = m[cur];
        for (int i : v)
        {
            if (i != prev)
            {
                if (deep(m, cur, i, visited,start))
                    return true;
            }
        }
        return false;
    }
}; */

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> v(edges.size() + 1);
        for (int i = 0; i < v.size(); i++)
            v[i] = i;

        for (vector<int> e : edges)
        {
            if (parent(e[0], v) == parent(e[1], v))
                return e;
            else
            {
                int a = parent(e[0], v);
                int b = parent(e[1], v);
                v[a] = v[b];
            }
        }
        return vector<int>();
    }

    int parent(int val, vector<int> &v)
    {
        if (v[val] == val)
            return val;

        return parent(v[val], v);
    }
};

int main()
{

    Solution s;

    vector<vector<int>> v = {
        {1, 3},
        {3, 4},
        {1, 5},
        {3, 5},
        {2, 3},
    };

    print_v(s.findRedundantConnection(v));
}
