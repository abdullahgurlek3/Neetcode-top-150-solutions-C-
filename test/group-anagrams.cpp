#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (string str : strs)
        {
            string x = str;
            sort(x.begin(), x.end());
            if (m.count(x))
            {
                m[x].push_back(str);
            }
            else
            {
                vector<string> v;
                v.push_back(str);
                m[x] = v;
            }
        }
        vector<vector<string>> r;
        for(const auto& i:m){
            r.push_back(i.second);
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    print_v_ar(s.groupAnagrams(v));
}
