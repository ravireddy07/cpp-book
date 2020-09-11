// https://leetcode.com/problems/power-of-two/

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        int i = 0;
        do
        {
            if (pow(2, i) == n)
                return true;
            else if (pow(2, i) > n)
                return false;
            else
                i++;
        } while (1);
    }
};

int main()
{
    Solution a;
    cout << a.isPowerOfTwo(16) << endl;
    return 0;
}