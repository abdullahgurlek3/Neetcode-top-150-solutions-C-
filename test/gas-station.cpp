#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        vector<int> vec;
        int total = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            vec.push_back(gas[i] - cost[i]);
            total += gas[i] - cost[i];
        }

        if (total < 0)
            return -1;

        for (int i = 0; i < gas.size(); i++)
        {
            int total = 0;
            bool found = true;
            while (i < gas.size() && gas[i] == 0)
            {
                i++;
            }

            for (int j = i; j < gas.size(); j++)
            {
                total += vec[j];
                if (total < 0)
                {
                    found = false;
                    break;
                }
            }
            if (!found)
            {
                continue;
            }

            int j = 0;
            while (j < i && gas[j] == 0)
            {
                j++;
            }

            for (; j < i; j++)
            {
                total += vec[j];
                if (total < 0)
                {
                    found = false;
                    break;
                }
            }
            if (found)
                return i;
        }
        return -1;
    }
};

int main()
{

    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};

    Solution s;
    cout << s.canCompleteCircuit(gas, cost);
}
