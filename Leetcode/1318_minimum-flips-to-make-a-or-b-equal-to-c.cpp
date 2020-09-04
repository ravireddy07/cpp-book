// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int count = 0;
        while (a | b != c)
        {
            // get left bits of each number
            int aa = a & 0x1;
            int bb = b & 0x1;
            int cc = c & 0x1;
            if (cc == 0) // if left bit of c is zero - both a and b have to be zero
            {
                if (aa == 1)
                {
                    count++;
                    a--;
                }
                if (bb == 1)
                {
                    count++;
                    b--;
                }
            }
            else // if left bit of c is one, either a or b have to be one
                if ((aa == 0) && (bb == 0))
            {
                count++;
                a += 1;
            }
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return count;
    }
};

int main()
{
    Solution a;
    cout << a.minFlips(4, 2, 7) << endl;
    return 0;
}