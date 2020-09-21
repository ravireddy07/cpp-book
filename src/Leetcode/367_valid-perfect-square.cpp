// https://leetcode.com/problems/valid-perfect-square/

#include <iostream>
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
    cout << a.isPerfectSquare(16) << endl;
    return 0;
}