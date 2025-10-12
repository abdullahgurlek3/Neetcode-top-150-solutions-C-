#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        map<int, set<int>> m;
        for (int i = 0; i < edges.size(); i++)
        {
            if (m.count(edges[i][0]))
            {
                m[edges[i][0]].insert(edges[i][1]);
            }
            else
            {
                m[edges[i][0]] = {edges[i][1]};
            }

            if (m.count(edges[i][1]))
            {
                m[edges[i][1]].insert(edges[i][0]);
            }
            else
            {
                m[edges[i][1]] = {edges[i][0]};
            }
        }

        for (int i = edges.size() - 1; i >= 0; i++)
        {
            unordered_set<int> visited;
            if (deep(m, edges[i][0], edges[i][0], visited))
                return edges[i];
        }
        return edges[0];
    }

    bool deep(map<int, set<int>> &m, int start, int init, unordered_set<int> &visited)
    {
        if (visited.count(start) && start != init)
            return true;
        if (visited.count(start))
            return false;
        visited.insert(start);
        for (int x : m[start])
        {
            if (deep(m, x, init, visited))
                return true;
        }

        return false;
    }
};

int main()
{

    Solution s;

    vector<vector<int>> v = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 4},
        {1, 5},
    };

    print_v(s.findRedundantConnection(v));
}
