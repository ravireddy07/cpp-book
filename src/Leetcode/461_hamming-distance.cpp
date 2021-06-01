// Problem Statement: https://leetcode.com/problems/hamming-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int count = 0, r;
        int z = x ^ y;
        for (int i = 0; z; i++)
        {
            r = z % 2;
            z /= 2;
            if (r == 1)
                count++;
        }
        return count;
    }
};

int main()
{
    Solution a;
    cout << a.hammingDistance(1, 4) << "\n";
    return 0;
}
