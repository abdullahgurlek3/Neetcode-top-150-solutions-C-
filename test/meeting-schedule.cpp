#include "iostream"
#include "helper.h"
#include "map"

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[i - 1].end)
                return false;
        }

        return true;
    }
};

int main()
{

    vector<Interval> l = {{1, 2}, {2, 3}, {3, 4}, {4, 12}};
    Solution s;
    cout << (s.canAttendMeetings(l));
}
