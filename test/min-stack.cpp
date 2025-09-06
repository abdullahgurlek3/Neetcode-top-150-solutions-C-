#include "iostream"
#include "helper.h"

class MinStack
{
public:
    vector<int> d;
    vector<int> ordered;

    void push(int val)
    {
        d.push_back(val);
        if (ordered.size() == 0)
        {
            ordered.push_back(val);
        }
        else
        {
            ordered.push_back(min(ordered.back(), val));
        }
    }

    void pop()
    {
        d.pop_back();
        ordered.pop_back();
    }

    int top()
    {
        return d[d.size() - 1];
    }

    int getMin()
    {
        return ordered[ordered.size() - 1];
    }
};

int main()
{
    MinStack m;
    m.push(2147483646);
    m.push(2147483646);
    m.push(2147483647);
    cout << m.top() << endl;
    m.pop();
    cout << m.getMin() << endl;
    m.pop();
    cout << m.getMin() << endl;
    m.pop();
    m.push(2147483647);
    cout << m.top() << endl;
    cout << m.getMin() << endl;
    m.push(-2147483648);

    cout << m.top() << endl;

    cout << m.getMin() << endl;
    m.pop();
    cout << m.getMin() << endl;
}
