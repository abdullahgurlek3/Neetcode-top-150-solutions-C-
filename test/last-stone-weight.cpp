#include "iostream"
#include "helper.h"
#include "map"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int stone:stones){
            q.push(stone);
        }   
        while (q.size()>1)
        {
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            q.push(abs(a-b));
        }

        return q.top();
        
    }
};

int main()
{
    vector<int> v = {4, 5, 8, 2};
    Solution s;
    cout << s.lastStoneWeight(v);
}
