#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int r = 1;
        int i = digits.size() - 1;
        while (i >= 0)
        {
            if (digits[i] + r > 9)
            {
                digits[i] = (digits[i] + r) % 10;
                r = 1;
            }
            else
            {
                digits[i] += r;
                r = 0;
                break;
            }
            i--;
        }
        if (r > 0)
        {
            vector<int> v;
            v.push_back(1);
            for (int c : digits)
                v.push_back(c);
            return v;
        }
        return digits;
    }
};

int main()
{
    vector<int> v = {9, 9, 9};
    Solution s;
    print_v((s.plusOne(v)));
}
