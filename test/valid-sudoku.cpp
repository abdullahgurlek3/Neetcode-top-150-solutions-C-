#include "iostream"
#include "helper.h"
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int y = 0; y < board.size(); y++)
        {
            unordered_map<char, bool> m;
            for (int x = 0; x < board[y].size(); x++)
            {
                if (board[y][x] == '.')
                {
                    continue;
                }

                if (m.count(board[y][x]))
                {
                    return false;
                }
                m[board[y][x]] = true;
            }
        }

        for (int x = 0; x < board[0].size(); x++)
        {
            unordered_map<char, bool> m;

            for (int y = 0; y < board.size(); y++)
            {

                if (board[y][x] == '.')
                {
                    continue;
                }

                if (m.count(board[y][x]))
                {
                    return false;
                }
                m[board[y][x]] = true;
            }
        }

        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                unordered_map<char, bool> m;
                for (int a = y * 3; a < (y + 1) * 3; a++)
                {
                    for (int b = x * 3; b < (x + 1) * 3; b++)
                    {
                        if (board[a][b] == '.')
                        {
                            continue;
                        }
                        if (m.count(board[a][b]))
                        {
                            return false;
                        }
                        m[board[a][b]] = true;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board;
    vector<char> l1 = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    vector<char> l2 = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    vector<char> l3 = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    vector<char> l4 = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    vector<char> l5 = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    vector<char> l6 = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    vector<char> l7 = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    vector<char> l8 = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    vector<char> l9 = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    board.push_back(l1);
    board.push_back(l2);
    board.push_back(l3);
    board.push_back(l4);
    board.push_back(l5);
    board.push_back(l6);
    board.push_back(l7);
    board.push_back(l8);
    board.push_back(l9);
    cout << s.isValidSudoku(board);
}
