#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    bool back(vector<vector<char>> &board, string word, int y, int x, int start, vector<vector<bool>> &visited)
    {
        if (y >= board.size())
            return false;
        if (x >= board[0].size())
            return false;
        if (y < 0 || x < 0)
            return false;

        if (board[y][x] != word[start])
        {
            return false;
        }

        if (visited[y][x])
        {
            return false;
        }

        if (start == word.size() - 1)
        {
            return true;
        }

        visited[y][x] = true;
        start += 1;
        if (back(board, word, y + 1, x, start, visited))
            return true;

        if (back(board, word, y - 1, x, start, visited))
            return true;

        if (back(board, word, y, x + 1, start, visited))
            return true;

        if (back(board, word, y, x - 1, start, visited))
            return true;
        start -= 1;

        visited[y][x] = false;

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size());
        for (int i = 0; i < board.size(); i++)
        {
            visited[i] = vector<bool>(board[0].size());
        }

        for (int y = 0; y < board.size(); y++)
        {
            for (int x = 0; x < board[0].size(); x++)
            {
                if (back(board, word, y, x, 0, visited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    Solution s;
    vector<vector<char>> st = {
        {'a', 'b'},
        {'c', 'd'},

    };
    cout << s.exist(st, "abdc");
}
