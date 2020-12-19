// https://leetcode.com/problems/palindrome-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return 0;
        long temp = 0;
        int act = x;
        while (x > 0)
        {
            temp *= 10 + x % 10;
            x /= 10;
        }
        if (temp == act)
            return true;
        return false;
    }
};

int main()
{
    Solution a;
    cout << a.isPalindrome(121) << endl;
    return 0;
}
