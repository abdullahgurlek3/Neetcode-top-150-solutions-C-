#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> v;
        while (i < j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                v.push_back(i + 1);
                v.push_back(j + 1);

                return v;
            }
            else if (numbers[i] + numbers[j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        v.push_back(-1);
        v.push_back(-1);

        return v;
    }
};

int main()
{
    Solution s;
    vector<int> v = {8, 12, 66, 40, 98, 33};
    sort(v.begin(), v.end());
    print_v(v);
    print_v(s.twoSum(v, 99));
}
