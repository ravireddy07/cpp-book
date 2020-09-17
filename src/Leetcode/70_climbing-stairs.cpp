// https://leetcode.com/problems/climbing-stairs/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int first = 1, second = 2;
        long int count = 0;
        for (int i = 3; i <= n; i++)
        {
            count = first + second;
            first = second;
            second = count;
        }
        return count;
    }
};

int main()
{
    Solution a;
    cout << a.climbStairs(2) << endl;
    return 0;
}