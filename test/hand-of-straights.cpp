#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        map<int, int> m;
        for (int c : hand)
            m[c]++;

        vector<pair<int, int>> v;
        for (const auto &item : m)
        {
            v.push_back({item.first, item.second});
        }
        sort(v.begin(), v.end());

        while (v.size() > 0)
        {

            int last = -1;
            vector<pair<int, int>> n;
            for (int i = 0; i < groupSize; i++)
            {
                if (v.size() == 0)
                    return false;
                if (last == -1)
                {
                    last = v.back().first;
                    int count = v.back().second;

                    v.pop_back();
                    if (count > 1)
                    {
                        n.push_back({last, count - 1});
                    }
                }
                else
                {
                    if (v.back().first != last - 1)
                    {
                        return false;
                    }
                    int count = v.back().second;
                    last = v.back().first;
                    v.pop_back();

                    if (count > 1)
                    {
                        n.push_back({last, count - 1});
                    }
                }
            }
                    sort(n.begin(), n.end());

            for (pair<int, int> p : n)
            {
                v.push_back(p);
            }
        }

        return true;
    }
};

int main()
{

    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};

    Solution s;
    cout << s.isNStraightHand(hand, 3);
}
