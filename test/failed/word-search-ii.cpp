#include "iostream"
#include "helper.h"
#include "map"

struct Trie
{
    bool end;
    Trie *children['z' - 'a' + 1];
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *trie = generateTrie(words);

        set<string> se;
        vector<vector<bool>> visited(board.size());
        for (int i = 0; i < board.size(); i++)
        {
            vector<bool> tmp(board[0].size());
            visited[i] = tmp;
        }

        for (int y = 0; y < board.size(); y++)
        {
            for (int x = 0; x < board[y].size(); x++)
            {
                back(board, trie, y, x, "", visited, se);
            }
        }
        vector<string> v;
        for(string w:se){
            v.push_back(w);
        }
        return v;
    }

    void back(vector<vector<char>> &board, Trie *trie, int y, int x, string str, vector<vector<bool>> &visited, set<string> &se)
    {
        if (y == board.size() || x == board[0].size() || y < 0 || x < 0)
        {
            return;
        }
        if (trie->end)
        {
            se.insert(str);
            cout << str << y << " " << x << endl;
        }
        Trie *local = trie;
        char c = board[y][x];
        if (!local->children[c - 'a'])
        {
            return;
        }
        if (visited[y][x])
        {
            return;
        }

        visited[y][x] = true;
        back(board, local->children[c - 'a'], y + 1, x, str + c, visited, se);
        back(board, local->children[c - 'a'], y, x + 1, str + c, visited, se);
        back(board, local->children[c - 'a'], y - 1, x, str + c, visited, se);
        back(board, local->children[c - 'a'], y, x - 1, str + c, visited, se);
        visited[y][x] = false;
    }

    Trie *generateTrie(vector<string> &words)
    {
        Trie *trie = new Trie{};
        for (string w : words)
        {
            Trie *local = trie;
            for (char c : w)
            {
                if (!local->children[c - 'a'])
                {
                    local->children[c - 'a'] = new Trie{};
                }
                local = local->children[c - 'a'];
            }
            local->end = true;
        }

        return trie;
    }
};

int main()
{

    Solution s;
    vector<vector<char>> st = {
        {'a'},

    };
    vector<string> v = {"a"};
    print_v(s.findWords(st, v));
}
