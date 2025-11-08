#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> mem(word1.size() + 1, vector<int>(word2.size() + 1));
        return dfs(word1, 0, word2, 0, mem);
    }

    int dfs(string &word1, int a, string &word2, int b, vector<vector<int>> &mem)
    {
        if (mem[a][b] > 0)
        {
            return mem[a][b];
        }

        if (a >= word1.size())
            return word2.size() - b;
        if (b >= word2.size())
            return word1.size() - a;

        if (word1[a] == word2[b])
            return dfs(word1, a + 1, word2, b + 1, mem);

        int mx = dfs(word1, a + 1, word2, b, mem);
        mx = min(mx, dfs(word1, a, word2, b + 1, mem));
        mx = min(mx, dfs(word1, a + 1, word2, b + 1, mem));

        mem[a][b] = mx + 1;
        return mx + 1;
    }
};
int main()
{
    Solution s;
    cout << s.minDistance("ccc", "ccccasfc");
}
