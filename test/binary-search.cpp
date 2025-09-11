#include "iostream"
#include "helper.h"
#include "map"

// class Solution
// {
// public:
//     int search(vector<int> &nums, int target)
//     {
//         map<int, int> m;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             m[nums[i]] = i;
//         }
//         return m.count(target) ? m[target] : -1;
//     }
// };

// class Solution
// {
// public:
//     int search(vector<int> &nums, int target)
//     {
//         int i = 0;
//         int j = nums.size() - 1;
//         while (j - i > 1)
//         {
//             int m = (i + j) / 2;
//             if (target > nums[m])
//             {
//                 i = m + 1;
//             }
//             else
//             {
//                 j = m;
//             }
//         }

//         if (target == nums[i])
//             return i;
//         if (target == nums[j])
//             return j;

//         return -1;
//     }
// };

// class Solution
// {
// public:
//     int search(vector<int> &nums, int target)
//     {
//         return deep(nums, 0, nums.size() - 1, target);
//     }
//     int deep(vector<int> &nums, int start, int end, int target)
//     {
//         if (start > end)
//         {
//             return -1;
//         }
//         if(nums[start]==target) return start;
//         if(nums[end]==target) return end;

//         int m = (start + end) / 2;
//         if (nums[m] == target)
//         {
//             return m;
//         }
//         else if (nums[m] > target)
//         {
//             return deep(nums, start, m-1 , target);
//         }
//         else
//         {
//             return deep(nums, m+1, end, target);
//         }
//     }
// };

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j)
        {
            int m = (i + j) / 2;
            if (nums[m] < target)
            {
                i = m + 1;
            }
            else
            {
                j = m;
            }
        }
        if (i < nums.size() && nums[j] == target)
        {
            return j;
        }

        return -1;
    }
};

int main()
{
    vector<int> v = {2, 5};
    Solution s;
    cout << s.search(v, 5);
}
