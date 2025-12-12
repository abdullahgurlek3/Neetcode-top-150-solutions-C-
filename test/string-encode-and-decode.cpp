#include "iostream"
#include "helper.h"

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        vector<char> ret;
        for (string str : strs)
        {
            char c = str.size();
            ret.push_back(c);
            for (char c : str)
                ret.push_back(c);
        }
        return string(ret.begin(), ret.end());
    }

    vector<string> decode(string s)
    {
        vector<string> ret;
        int i = 0;
        while (i < s.size())
        {
            int f = s[i];
            if (f < 0)
            {
                f = 256 + f;
            }

            i++;
            string str = "";
            while (f > 0)
            {
                str += s[i];
                i++;
                f--;
            }
            ret.push_back(str);
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<string> v = {"VeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimesVeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimes"};
    vector<string> ret = (s.decode(s.encode(v)));
    print_v(ret);
}
