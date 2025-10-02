#include "iostream"
#include "helper.h"
#include "unordered_set"
#include "map"

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, vector<string>> m;

        set<string> cur(wordList.begin(), wordList.end());
        cur.insert(beginWord);        
        for (string w : cur)
        {
            for (string w2 : wordList)
            {
                if (w == w2)
                    continue;
                int i = 0;
                int d = 0;
                while (d < 2 && i < w.size())
                {
                    if (w[i] != w2[i])
                        d++;
                    i++;
                }
                if (d < 2)
                {
                    if (m.count(w))
                    {
                        m[w].push_back(w2);
                    }
                    else
                    {
                        m[w] = {w2};
                    }
                }
            }
        }

        deque<string> q;
        q.push_back(beginWord);
        int level = 0;
        unordered_set<string> visited;
        while (q.size() > 0)
        {
            deque<string> n;
            while (q.size() > 0)
            {
                string f = q.back();
                q.pop_back();
                if (visited.count(f))
                    continue;
                if (f == endWord)
                {
                    return level + 1;
                }
                visited.insert(f);

                for (string &w : m[f])
                {
                    n.push_back(w);
                }
            }
            q = n;
            level++;
        }
        return 0;
    }
};

int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution s;
    cout << s.ladderLength("hit", "cog", wordList);
}
