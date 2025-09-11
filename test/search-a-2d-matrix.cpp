#include "iostream"
#include "helper.h"
#include "unordered_set"

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int i = 0;
        int j = matrix.size() - 1;
        while (i <= j)
        {
            int m = (i + j) / 2;
            if (target >= matrix[m][0] && target <= matrix[m][matrix[m].size() - 1])
            {
                cout << " found " << endl;
                int x = 0;
                int y = matrix[m].size() - 1;
                while (x <= y)
                {
                    int mx = (x + y) / 2;
                    if (matrix[m][mx] == target)
                        return true;
                    if (target >= matrix[m][mx])
                    {
                        x = mx + 1;
                    }
                    else
                    {
                        y = mx - 1;
                    }
                }
                if (matrix[m][x] == target)
                    return true;
                return false;
            }
            else if (target >= matrix[m][matrix[m].size() - 1])
            {
                i = m + 1;
            }
            else
            {
                j = m - 1;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    cout << s.searchMatrix(convertStrToMatrix("[[1]]"), 1);
}
