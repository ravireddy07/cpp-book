// https://leetcode.com/problems/number-of-1-bits/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        for (int i = 0; i <= 31; i++)
            count += ((n >> i) & (0x1));
        return count;
        //return __builtin_popcount(n);
    }
};

int main()
{
    Solution a;
    cout << a.hammingWeight(00000000000000000000000000001011) << endl;
    return 0;
}