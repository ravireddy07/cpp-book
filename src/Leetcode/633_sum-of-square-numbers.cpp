// Problem Statement: https://leetcode.com/problems/sum-of-square-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c == 0)
            return 1;
        for (int i = 1; i <= sqrt(c); i++)
        {
            int val = i * i;
            double x = sqrt(c - val);
            if (ceil(x) == floor(x))
                return true;
        }
        return false;
    }
};

int main()
{
    Solution a;
    cout << a.judgeSquareSum(5) << "\n";
    return 0;
}
