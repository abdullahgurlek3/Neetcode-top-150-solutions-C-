#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        vector<int> v(n), rate(n);
        for (int i = 0; i < n; i++)
            v[i] = i;

        for (vector<int> e : edges)
        {
            if (find(e[0], v) == find(e[1], v))
                return false;
            else
                un(e[0], e[1], v, rate);
        }
       
        print_v(v);
        return true;
    }

    int find(int a, vector<int> &v)
    {
        if (v[a] == a)
            return a;
        return find(v[a], v);
    }

    void un(int a, int b, vector<int> &v, vector<int> &rate)
    {
        int x = find(a, v);
        int y = find(b, v);
        if (x != y)
        {
            if (rate[y] > rate[x])
            {
                v[y] = x;
            }
            else if (rate[y] < rate[x])
            {
                v[x] = y;
            }
            else
            {
                rate[y] = x;
                rate[x]++;
            }
        }
    }
};

int main()
{

    Solution s;
    vector<vector<int>> st = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 4},
    };

    cout << s.validTree(5, st);
}
