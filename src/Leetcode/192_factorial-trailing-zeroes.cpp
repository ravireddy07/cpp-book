// https://leetcode.com/problems/factorial-trailing-zeroes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 1;
        for (int i = 1; i <= n; ++i)
            res *= i;
        string str = to_string(res);
        res = 0;
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == '0')
                res++;
            else
                res = 0;
        }
        return res;
    }
};

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        while (n)
        {
            n /= 5;
            res += n;
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.trailingZeroes(5) << endl;
    return 0;
}