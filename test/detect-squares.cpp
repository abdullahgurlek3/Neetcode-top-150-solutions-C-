#include "iostream"
#include "helper.h"

class DetectSquares
{
public:
    vector<vector<int>> points;

    void add(vector<int> point)
    {
        points.push_back(point);
        sort(point.begin(), point.end());
    }

    int count(vector<int> point)
    {
        for (vector<int> p : points)
        {
            
        }
        return 1;
    }
};

int main()
{
    DetectSquares *obj = new DetectSquares();
    obj->add({0, 1});
    int param_2 = obj->count({0, 1});
}
