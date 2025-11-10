#include "iostream"
#include "helper.h"
class DetectSquares
{
public:
    vector<vector<int>> points;
    void add(vector<int> point)
    {
        points.push_back(point);
        sort(points.begin(), points.end());
    }

    int count(vector<int> point)
    {
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {

            }
        }
    }
};

int main()
{
    DetectSquares *obj = new DetectSquares();
    obj->add({0, 1});
    int param_2 = obj->count({0, 1});
}
