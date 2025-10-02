#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> r;

        vector<deque<string>> d = partitionSub(s);
        for (deque<string> x : d)
        {
            vector<string> v;
            while (x.size() > 0)
            {
                v.push_back(x.back());
                x.pop_back();
            }
            r.push_back(v);
        }
        return r;
    }

    vector<deque<string>> partitionSub(string s)
    {
        vector<deque<string>> v;
        for (int i = 0; i < s.size(); i++)
        {
            int j = 0;
            int k = i;
            bool ispal = true;
            while (j < k)
            {
                if (s[j] != s[k])
                {
                    ispal = false;
                    break;
                }

                j++;
                k--;
            }

            if (ispal)
            {
                if (i + 1 == s.size())
                {
                    v.push_back({s.substr(0, i + 1)});
                }
                else
                {
                    vector<deque<string>> ret = partitionSub(s.substr(i + 1));
                    for (int p = 0; p < ret.size(); p++)
                    {
                        ret[p].push_back(s.substr(0, i + 1));
                        v.push_back(ret[p]);
                    }
                }
            }
        }

        return v;
    }
};

int main()
{

    Solution s;
    vector<vector<string>> v = s.partition("efe");
    for (int y = 0; y < v.size(); y++)
    {
        for (int x = 0; x < v[y].size(); x++)
        {
            cout << v[y][x] << " ";
        }
        cout << endl;
    }
}
