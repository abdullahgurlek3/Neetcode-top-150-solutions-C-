#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        vector<vector<int>> all;

        for (int i = num1.size() - 1; i >= 0; i--)
        {
            int r = 0;
            vector<int> ret;
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                pair<int, int> p = m(num1[i], num2[j], r);
                r = p.second;
                ret.push_back(p.first);
            }
            if (r > 0)
                ret.push_back(r);
            reverse(ret.begin(), ret.end());
            for (int k = 0; k < num1.size() - 1 - i; k++)
            {
                ret.push_back(0);
            }

            all.push_back(ret);
        }
        return sum(all);
    }

    string sum(vector<vector<int>> &all)
    {
        vector<int> ret;
        int i = 0;
        int r = 0;
        while (true)
        {
            bool found = true;
            int local = r;
            for (vector<int> &curr : all)
            {
                if (i < curr.size())
                {
                    local += curr[curr.size() - 1 - i];
                    found = false;
                }
            }
            if (found)
                break;
            r = local / 10;
            ret.push_back(local % 10);
            i++;
        }
        if (r > 0)
            ret.push_back(r);

        reverse(ret.begin(), ret.end());

        string str = "";
        bool start = true;
        for (int t : ret)
        {
            if (start && t == 0)
            {
                continue;
            }
            if (t != 0)
                start = false;
            str += to_string(t);
        }
        if(str=="") return "0";
        return str;
    }

    pair<int, int> m(char &a, char &b, int r)
    {
        int t = (a - '0') * (b - '0') + r;
        return {t % 10, t / 10};
    }
};

int main()
{
    Solution s;
    cout << ((s.multiply("9133", "0")));
}
