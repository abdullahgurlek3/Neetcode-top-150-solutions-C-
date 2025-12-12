#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, double>> v;
        for (int i = 0; i < position.size(); i++)
        {
            v.push_back({position[i], (target - position[i]) / float(speed[i])});
        }
        sort(v.begin(), v.end());

        int count = 0;

        while (v.size() > 1)
        {
            pair<int, double> last = v.back();
            v.pop_back();
            if (last.second < v.back().second)
            {
                count++;
            }
            else
            {
                v.pop_back();
                v.push_back(last);
            }
        }

        return count + v.size();
    }
};

int main()
{
    vector<int> position = {6, 8};
    vector<int> speedddd = {3, 2};

    Solution s;
    cout << (s.carFleet(10, position, speedddd));
}
