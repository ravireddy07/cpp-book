// Problem Statement: https://leetcode.com/problems/string-to-integer-atoi/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int i = 0, flag = 0;
        long long p = 0;
        while (i < str.length() && str[i] == ' ')
            i++;

        if (i < str.length() && str[i] == '+')
            i++;
        else if (i < str.length() && str[i] == '-')
        {
            flag = 1;
            i++;
        }

        for (; i < str.length(); i++)
        {
            if (p == 0 && (str[i] < 48 || str[i] > 57))
                return 0;
            if (str[i] > 47 && str[i] < 58)
            {
                p = p * 10 + str[i] - 48;
                if (p > INT_MAX)
                {
                    if (flag)
                        return INT_MIN;
                    return INT_MAX;
                }
            }
            else
                break;
        }

        if (flag)
            return -p;
        return p;
    }
};

int main()
{
    Solution a;
    cout << a.myAtoi("42") << "\n";
    return 0;
}
