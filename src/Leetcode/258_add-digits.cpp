// Problem Statement: https://leetcode.com/problems/add-digits/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        if (num < 10)
            return num;
        int sum = 0;
    again:
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        if (sum < 10)
            return sum;
        else
        {
            num = sum;
            sum = 0;
            goto again;
        }
        return sum;
    }
};

int main()
{
    Solution a;
    cout << a.addDigits(18) << "\n";
    return 0;
}
