#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<pair<int, int>> v;
        vector<vector<string>> ret;

        back(v, n, 0, ret);
        return ret;
    }

    void back(vector<pair<int, int>> &v, int n, int index, vector<vector<string>> &ret)
    {
        if (v.size() > 1)
        {
            pair<int, int> last = v[v.size() - 1];
            for (int k = 0; k < v.size() - 1; k++)
            {
                pair<int, int> sl = v[k];
                if (sl.first == last.first || sl.second == last.second)
                {
                    return;
                }
                if (last.first - last.second == sl.first - sl.second)
                {
                    return;
                }
                if (last.first + last.second == sl.second + sl.first)
                {
                    return;
                }
            }
        }
        if (index == n)
        {
            vector<string> local(n);

            for (int i = 0; i < n; i++)
            {
                string str = "";
                for (int k = 0; k < n; k++)
                {
                    str += '.';
                }
                local[i] = str;
            }

            for (int i = 0; i < v.size(); i++)
            {
                local[v[i].first][v[i].second] = 'Q';
            }

            ret.push_back(local);

            return;
        }

        for (int i = 0; i < n; i++)
        {
            v.push_back({index, i});
            back(v, n, index + 1, ret);
            v.pop_back();
        }
    }
};

int main()
{

    Solution s;
    s.solveNQueens(4);
}
