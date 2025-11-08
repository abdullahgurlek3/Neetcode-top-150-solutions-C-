#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {

        map<int, int> m;
        for (int h : hand)
        {
            m[h]++;
        }

        deep(m);

        return true;
    }

    void deep(map<int, int> m)
    {
        
    }
};

int main()
{

    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};

    Solution s;
    cout << s.isNStraightHand(hand, 3);
}
