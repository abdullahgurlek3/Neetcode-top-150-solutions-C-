#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        deque<pair<int, int>> q;
        for (int x = 0; x < board[0].size(); x++)
        {
            if (board[0][x] == 'O')
                q.push_back({0, x});
            if (board.size() > 1 && board[board.size() - 1][x] == 'O')
                q.push_back({board.size() - 1, x});
        }

        for (int y = 1; y < board.size() - 1; y++)
        {
            if (board[y][0] == 'O')
                q.push_back({y, 0});
            if (board[0].size() > 1 && board[y][board[y].size() - 1] == 'O')
                q.push_back({y, board[y].size() - 1});
        }

        deque<pair<int, int>> end;

        while (q.size() > 0)
        {
            pair<int, int> last = q.front();
            q.pop_front();

            end.push_back(last);
            int y = last.first;
            int x = last.second;
            board[y][x]='Z';

            if (y + 1 < board.size() && board[y + 1][x] == 'O')
                q.push_back({y + 1, x});
            if (y > 0 && board[y - 1][x] == 'O')
                q.push_back({y - 1, x});
            if (x + 1 < board[0].size() && board[y][x + 1] == 'O')
                q.push_back({y, x + 1});
            if (x > 0 && board[y][x - 1] == 'O')
                q.push_back({y, x - 1});
        }
       

        for (int y = 0; y < board.size(); y++)
        {
            for (int x = 0; x < board[0].size(); x++)
            {
                if (board[y][x] == 'Z')
                    board[y][x] = 'O';
                else
                    board[y][x] = 'X';
            }
        }
    }
};

int main()
{

    vector<vector<char>> v = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    Solution s;
    s.solve(v);
}
