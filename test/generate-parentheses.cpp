#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        deep("", n, n, &v);
        return v;
    }
    void deep(string str, int x, int y, vector<string> *v)
    {
        if (x == 0 && y == 0)
        {
            v->push_back(str);
        }
        if (x > 0)
        {
            deep(str + "(", x - 1, y, v);
        }
        if (x < y && y > 0)
        {
            deep(str + ")", x, y - 1, v);
        }
    }
};

int main()
{
    Solution s;
    print_v(s.generateParenthesis(2));
}
