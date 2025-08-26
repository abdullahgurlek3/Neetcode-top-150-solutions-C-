#include "iostream"
#include "helper.h"
#include "map"
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, bool> m;
        for (int v : nums)
        {
            m[v] = true;
        };

        int mx = 0;

        unordered_map<int, bool> visited;
        for (const auto v : m)
        {
            if (visited.count(v.first))
            {
                continue;
            }
            int i = v.first;
            int j = v.first + 1;
            int count = 0;
            while (m.count(i) > 0)
            {
                visited[i] = true;
                count++;
                i--;
            }

            while (m.count(j) > 0)
            {
                visited[j] = true;
                count++;
                j++;
            }

            if (count > mx)
                mx = count;
        }
        return mx;
    }
};

int main()
{
    Solution s;
    vector<int> v = {0,3,7,2,5,8,4,6,0,1};
    cout << (s.longestConsecutive(v));
}
