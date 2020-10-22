// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int res = 0, count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                count++;
            else if (s[i] == ')')
                count--;
            res = max(count, res);
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.maxDepth("(1+(2*3)+((8)/4))+1") << endl;
    return 0;
}