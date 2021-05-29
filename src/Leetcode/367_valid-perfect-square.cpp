// Problem Statement: https://leetcode.com/problems/valid-perfect-square/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long long res = 1, count = 1;
        while (1)
        {
            if (res == num)
                return true;
            else if (res < num)
            {
                res = count * count;
                count++;
            }
            else
                return false;
        }
        return false;
    }
};

int main()
{
    Solution a;
    cout << a.isPerfectSquare(16) << "\n";
    return 0;
}
