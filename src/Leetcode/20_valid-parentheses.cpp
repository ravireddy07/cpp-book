// https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool leftbr(char X)
    {
        if (X == '(' || X == '[' || X == '{')
            return true;
        else
            return false;
    }
    bool rightbr(char X)
    {
        if (X == ')' || X == '}' || X == ']')
            return true;
        else
            return false;
    }
    bool matchchar(char X, char Y)
    {
        if (X == ')' && Y == '(' || X == '}' && Y == '{' || X == ']' && Y == '[')
            return true;
        else
            return false;
    }

    bool isValid(string s)
    {
        stack<char> st;
        int i = 0;
        while (s[i] != '\0')
        {
            if (leftbr(s[i]))
                st.push(s[i]);
            if (rightbr(s[i]))
            {
                if (st.empty())
                    return false;
                if (matchchar(s[i], st.top()))
                    st.pop();
                else
                    return false;
            }
            i++;
        }
        if (!st.empty())
            return false;
        return true;
    }
};

int main()
{
    Solution a;
    cout << a.isValid("([)]") << endl;
    return 0;
}