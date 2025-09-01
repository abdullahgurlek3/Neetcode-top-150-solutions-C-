#include "iostream"
#include "helper.h"
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            while (i < j && !(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9')))
            {
                i++;
            }
            while (i < j && !(('a' <= s[j] && s[j] <= 'z') || ('A' <= s[j] && s[j] <= 'Z') || ('0' <= s[j] && s[j] <= '9')))
            {
                j--;
            }
            if (!(s[i] == s[j] || 'a' <= max(s[i], s[j]) && 'z' >= max(s[i], s[j]) && (max(s[i], s[j]) - ('a' - 'A') == min(s[i], s[j]))))
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome("0P");
}
