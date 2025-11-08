#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        if (nums[0] == 0)
            return false;
        vector<bool> st(nums.size());
        st[0] = true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (st[i])
            {
                for (int j = i + 1; j < min(i + nums[i] + 1, int(nums.size())); j++)
                {
                    st[j] = true;
                    if (j == st.size() - 1)
                        return true;
                }
            }
        }
        return st[st.size() - 1];
    }
};

int main()
{

    vector<int> v = {1, 1, 1, 1};
    Solution s;
    cout << s.canJump(v);
}
