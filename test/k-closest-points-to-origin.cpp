#include "iostream"
#include "helper.h"
#include "map"

// struct Obj
// {
//     int size;
//     vector<int> v;
//     bool operator<(const Obj &obj) const
//     {
//         return obj.size > size;
//     }
// };

// class Solution
// {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
//     {
//         priority_queue<Obj> p;
//         for (vector<int> t : points)
//         {
//             p.push({t[0] * t[0] + t[1] * t[1], t});
//             if (p.size() > k)
//             {
//                 p.pop();
//             }
//         }
//         vector<vector<int>> r;

//         while (p.size() > 0)
//         {
//             r.push_back(p.top().v);
//             p.pop();
//         }

//         return r;
//     }
// };

struct Obj
{
    int size;
    vector<int> v;
    bool operator<(const Obj &obj) const
    {
        return obj.size > size;
    }
};

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return (a[0] * a[0] + a[1] * a[1]) - (b[0] * b[0] + b[1] * b[1]) < 0;
    }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        sort(points.begin(), points.end(), comp);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

int main()
{
    vector<vector<int>> points = {{1, 2}, {3, 4}, {1, 1}, {7, 8}};
    Solution s;
    s.kClosest(points, 2);
}
