#include "iostream"
#include "helper.h"
#include "map"

struct Pair
{
    int pos;
    int speed;
};

class Solution
{
public:
    static bool sp(Pair a, Pair b)
    {
        return a.pos - b.pos < 0;
    }
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<Pair> pairs(position.size());
        for (int i = 0; i < position.size(); i++)
        {
            pairs[i] = Pair{pos : position[i], speed : speed[i]};
        }
        sort(pairs.begin(), pairs.end(), sp);

        deep(&pairs);

        return 1;
    }

    void deep(vector<Pair> *pairs)
    {
        for (int i = 1; i < pairs->size(); i++)
        {
            cout << (*pairs)[i].pos << " " << (*pairs)[i].speed << endl;
            if (((*pairs)[i].speed < (*pairs)[i - 1].speed) && (*pairs)[i].pos * (*pairs)[i-1].speed -(*pairs)[i].pos * (*pairs)[i-1].speed - )
            {
            }
        }
    }
};

int main()
{
    vector<int> position = {8, 0, 5, 10, 3};
    vector<int> speedddd = {4, 1, 1, 2, 3};

    Solution s;
    cout << (s.carFleet(12, position, speedddd));
}
