#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> grid(text1.size(), vector<int>(text2.size()));
        for (int i = 0; i < text1.size(); i++)
        {
            for (int j = 0; j < text2.size(); j++)
            {
                if (text1[i] == text2[j])
                {
                    if (i == 0 || j == 0)
                    {
                        grid[i][j] = 1;
                    }
                    else
                    {
                        grid[i][j] = max(grid[i][j - 1], grid[i - 1][j - 1] + 1);
                    }
                }
                else
                {
                    if (j > 0)
                    {
                        grid[i][j] = max(grid[i][j], grid[i][j - 1]);
                    }
                    if (i > 0)
                    {
                        grid[i][j] = max(grid[i][j], grid[i - 1][j]);
                    }
                }
                
            }
        }
        return grid[text1.size()-1][text2.size()-1];
    }
};

// class Solution
// {
// public:
//     int longestCommonSubsequence(string text1, string text2)
//     {
//         return deep(text1, 0, text2, 0);
//     }

//     int deep(string& text1, int s1, string& text2, int s2)
//     {
//         if (s1 == text1.size() || s2 == text2.size())
//         {
//             return 0;
//         }
//         if (text1[s1] == text2[s2])
//         {
//             return 1 + deep(text1, s1 + 1, text2, s2 + 1);
//         }
//         return max(deep(text1, s1 + 1, text2, s2), deep(text1, s1, text2, s2 + 1));
//     }
// };

int main()
{

    Solution s;
    cout << s.longestCommonSubsequence("abc", "abcc");
}
