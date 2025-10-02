#include "iostream"
#include "helper.h"
#include "map"
/*
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, unordered_map<int, bool>> m;
        for (vector<int> p : prerequisites)
        {
            if (!m.count(p[0]))
            {
                m[p[0]] = *new unordered_map<int, bool>;
            }
            m[p[0]][p[1]] = true;
        }

        unordered_map<int, bool> cache;

        for (vector<int> p : prerequisites)
        {
            unordered_map<int, bool> visited;
            if (!check(p[0], visited, m, cache))
                return false;
        }
        return true;
    }

    bool check(int start, unordered_map<int, bool> &visited, unordered_map<int, unordered_map<int, bool>> &m, unordered_map<int, bool> &cache)
    {
        if (cache.count(start))
        {
            return cache[start];
        }

        if (visited.count(start))
        {
            return false;
        }
        visited[start] = true;
        if (!m.count(start))
        {
            return true;
        }

        unordered_map<int, bool> &s = m[start];

        for (const auto &item : s)
        {
            if (!check(item.first, visited, m, cache))
                return false;

            cache[item.first] = true;

            visited.erase(item.first);
        }

        return true;
    }
};

*/

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, unordered_map<int, bool>> m;
        for (vector<int> p : prerequisites)
        {
            if (!m.count(p[0]))
            {
                m[p[0]] = *new unordered_map<int, bool>;
            }
            m[p[0]][p[1]] = true;
        }

        map<int, bool> cache;

        for (int i = 1; i <= numCourses; i++)
        {
            if (cache.count(i))
            {
                continue;
            }

            set<int> visited;
            if (!dfs(i, visited, m, cache))
                return false;
        }

        return true;
    }

    bool dfs(int start, set<int> visited, unordered_map<int, unordered_map<int, bool>> &m, map<int, bool> &cache)
    {
        if (cache.count(start))
        {
            return cache[start];
        }
        
        if (visited.count(start))
            return false;
        visited.insert(start);

        for (auto const &item : m[start])
        {
            if (!dfs(item.first, visited, m, cache))
                return false;
            else cache[item.first]=true;
        }
        cache[start] = true;
        return true;
    }
};

int main()
{

    vector<vector<int>> v = {
        {1, 4},
        {2, 4},
        {3, 1},
        {3, 2},

    };

    Solution s;
    cout << s.canFinish(5, v);
}
