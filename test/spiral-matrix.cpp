#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ret;
        int i = 0;
        while (i <= min(matrix.size() / 2, matrix[0].size() / 2 ))
        {
            int xs = i;
            while (xs < matrix[0].size() - i)
            {
                ret.push_back(matrix[i][xs]);
                xs++;
            }

            if(ret.size() == matrix.size()*matrix[0].size()) break;
            xs--;
            int ye = i + 1;
            while (ye < matrix.size() - i)
            {
                ret.push_back(matrix[ye][xs]);
                ye++;
            }
      
            ye--;
            xs--;
            while (xs >= i)
            {
                ret.push_back(matrix[ye][xs]);
                xs--;
            }
            if(ret.size() == matrix.size()*matrix[0].size()) break;

            xs++;
            ye--;
            while (ye >= i + 1)
            {
                ret.push_back(matrix[ye][xs]);
                ye--;
            }

            i++;
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> l =
        {
            {1,2,3}};
    Solution s;
    print_v(s.spiralOrder(l));
}
