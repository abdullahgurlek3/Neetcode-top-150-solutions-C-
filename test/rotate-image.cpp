#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int s = 0;
        int e = matrix.size() - 1;

        while (s < e)
        {
            for (int i = 0; i < e-s; i++)
            {
                int t = matrix[s][s + i];
                matrix[s][s + i] = matrix[e - i][s];
                matrix[e - i][s] = matrix[e][e - i];
                matrix[e][e - i] = matrix[s + i][e];
                matrix[s + i][e] = t;
            }
            s++;
            e--;
        }
    }
};

int main()
{

    vector<vector<int>> l =
        {{2, 29, 20, 26, 16, 28},
         {12, 27, 9, 25, 13, 21},
         {32, 33, 32, 2, 28, 14},
         {13, 14, 32, 27, 22, 26},
         {33, 1, 20, 7, 21, 7},
         {4, 24, 1, 6, 32, 34}};
    Solution s;
    (s.rotate(l));
    print_matrix(l);
}
