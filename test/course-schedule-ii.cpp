#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> v(numCourses);
        vector<int> ret;
        for (vector<int> &p : prerequisites)
        {
            v[p[0]].push_back(p[1]);
        }
        set<int> tmp_visited;
        set<int> perm_visited;

        for (int i = 0; i < numCourses; i++)
        {
            set<int> local_visited;
            if (!deep(v, tmp_visited, perm_visited, i, ret, local_visited))
                return vector<int>();
        }

        return ret;
    }
    bool deep(vector<vector<int>> &v, set<int> &tmp_visited, set<int> &perm_visited, int start, vector<int> &ret, set<int> &local_visited)
    {
        if (local_visited.count(start))
        {
            return false;
        }

        if (tmp_visited.count(start) || perm_visited.count(start))
            return true;
        tmp_visited.insert(start);

        local_visited.insert(start);

        for (int item : v[start])
        {
            if (!deep(v, tmp_visited, perm_visited, item, ret, local_visited))
                return false;
        }
        ret.push_back(start);
        perm_visited.insert(start);
        local_visited.erase(start);

        return true;
    }
};

int main()
{

    vector<vector<int>> v = {
        {2, 3},
        {1, 2},
        {0, 1},
        {0, 4},
        {4, 5},
        {5, 1}};

    Solution s;
    print_v(s.findOrder(6, v));
}
