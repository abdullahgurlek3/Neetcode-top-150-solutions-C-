#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        map<char, vector<char>> m;
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};

        vector<string> ret;

        for (int i = 0; i < digits.size(); i++)
        {
            if (ret.size() == 0)
            {
                for (char c : m[digits[i]])
                {
                    string s(1, c);

                    ret.push_back(s);
                }
            }
            else
            {
                vector<string> cur;
                for (string s : ret)
                {
                    for (char c : m[digits[i]])
                    {
                        cur.push_back(s + (c));
                    }
                }
                ret = cur;
            }
        }
        return ret;
    }
};

int main()
{

    Solution s;

    print_v(s.letterCombinations("23"));
}
