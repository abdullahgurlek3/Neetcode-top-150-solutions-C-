#include "iostream"
#include "helper.h"
#include "map"
class MedianFinder
{
public:
    priority_queue<int> mx;                            // left
    priority_queue<int, vector<int>, greater<int>> mn; // right

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        mn.push(num);
        if (mx.size() > 0)
        {
            mn.push(mx.top());
            mx.pop();
            mx.push(mn.top());
            mn.pop();
        }
        if (mn.size() > mx.size())
        {
            mx.push(mn.top());
            mn.pop();
        }
    }

    double findMedian()
    {
        if (mn.size() == mx.size())
        {
            return (mn.top() + mx.top()) / 2.0;
        }
        else
        {

            return mx.top();
        }
    }
};

int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(-1);
    cout << obj->findMedian() << endl;
    obj->addNum(-2);
    cout << obj->findMedian() << endl;
    obj->addNum(-3);
    cout << obj->findMedian() << endl;
    obj->addNum(-4);
    cout << obj->findMedian() << endl;
    obj->addNum(-5);
    cout << obj->findMedian() << endl;
    obj->addNum(112);
    cout << obj->findMedian() << endl;
    obj->addNum(13);
    cout << obj->findMedian() << endl;
}
