#include "iostream"
#include "helper.h"

class Solution
{
public:
    char rev(char c){
        if(c=='{') return '}';
        if(c=='(') return ')';
        if(c=='[') return ']';
        return ' ';
    }
    bool isValid(string s)
    {
        if (s.size() % 2 == 1)
            return false;
            
        vector<char> v;

        for(char c:s){
            if (c=='{' || c=='(' || c=='[' )
            {
                v.push_back(c);
            }else{
                if(v.size()==0 || (rev(v.back()) != (c))){
                    return false;
                }
                v.pop_back();
            }
           
        }
        return v.size()==0;
    }
};

int main()
{
    Solution s;
    cout << s.isValid("()");
}
