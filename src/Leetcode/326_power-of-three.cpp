// https://leetcode.com/problems/power-of-three/

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        int i = 0;
        while (1)
        {
            if (pow(3, i) > n)
                return false;
            else if (pow(3, i) == n)
                return true;
            i++;
        }
        return false;
    }
};

int main()
{
    Solution a;
    cout << a.isPowerOfThree(27) << endl;
    return 0;
}