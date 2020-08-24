//Problem Link:  https://leetcode.com/problems/valid-number/
#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        int n = s.size(), i = 0, digits = 0, dots = 0;
        for (; i < n && isspace(s[i]); i++)
            ;
        if (s[i] == '+' || s[i] == '-')
        {
            i++;
        }
        for (; i < n && (isdigit(s[i]) || s[i] == '.'); i++)
        {
            isdigit(s[i]) ? digits++ : dots++;
        }
        if (!digits || dots > 1)
        {
            return false;
        }
        if (s[i] == 'e')
        {
            i++;
            if (s[i] == '+' || s[i] == '-')
            {
                i++;
            }
            digits = 0;
            for (; i < n && isdigit(s[i]); i++)
            {
                digits++;
            }
            if (!digits)
            {
                return false;
            }
        }
        for (; i < n && isspace(s[i]); i++)
            ;
        return i == n;
    }
};

int main()
{
    Solution a;
    string input = "0";
    bool result = a.isNumber(input);
    cout << result << endl;
    return 0;
}
