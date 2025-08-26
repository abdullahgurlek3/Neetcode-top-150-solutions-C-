#include "iostream"
#include "helper.h"

bool containsDuplicate(vector<int> &nums)
{
    set<int> s;

    for (int c : nums)
    {
        if (s.count(c) > 0)
            return true;
        s.insert(c);
    }
    return false;
}

int main()
{
    vector<int> v = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    cout << containsDuplicate(v);
}
