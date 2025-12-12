#include "iostream"
#include "helper.h"
#include "map"

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = 0;
        int e1 = nums1.size() - 1;
        int s2 = 0;
        int e2 = nums2.size() - 1;

        bool fmx = true;
        pair<int, int> last;
        while (s1 <= e1 && s2 <= e2)
        {
            if (fmx)
            {
                if (nums1[e1] > nums2[e2])
                {
                    last.first = last.second;
                    last.second = nums1[e1];
                    e1--;
                }
                else
                {
                    last.first = last.second;
                    last.second = nums2[e2];
                    e2--;
                }
                fmx = false;
            }
            else
            {
                if (nums1[s1] < nums2[s2])
                {
                    last.first = last.second;
                    last.second = nums1[s1];
                    s1++;
                }
                else
                {
                    last.first = last.second;
                    last.second = nums2[s2];
                    s2++;
                }
                fmx = true;
            }
        }

        while (s1 <= e1)
        {
            if (fmx)
            {
                last.first = last.second;
                last.second = nums1[e1];
                e1--;
                fmx = false;
            }
            else
            {
                last.first = last.second;
                last.second = nums1[s1];
                s1++;
                fmx = true;
            }
        }

        while (s2 <= e2)
        {
            if (fmx)
            {

                last.first = last.second;
                last.second = nums2[e2];
                e2--;
                fmx = false;
            }
            else
            {
                last.first = last.second;
                last.second = nums2[s2];
                s2++;
                fmx = true;
            }
        }

        if ((nums1.size() + nums2.size()) % 2 == 0)
        {
            return (last.second + last.first) / 2.0;
        }

        return last.second;
    }
};

int main()
{
    vector<int> a = {2, 5, 7};
    vector<int> b = {1, 3, 10};

    Solution s;
    cout << s.findMedianSortedArrays(a, b);
}
