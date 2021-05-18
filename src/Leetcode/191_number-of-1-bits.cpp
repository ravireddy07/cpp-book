// Problem Statement: https://leetcode.com/problems/number-of-1-bits/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }

    int hammingWeight(uint32_t n) {
        int cnt = 0; // count of set bit
        while (n > 0) { // iterate until all bits are traversed
            if ((n & 1) > 0) // check the parity of first bit from right
                ++cnt;
            n = n >> 1; //n=n/2, shift one bit to right
        }
        return cnt;
    }

    int hammingWeight(uint32_t n) {
        int cnt = 0; // count of set bit
        ++cnt;
        n = n & (n - 1); // change the first set bit from right to 0
    }
    return cnt;

    int hammingWeight(uint32_t n) {
        return __builtin_popcountll(n);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution a;
    int t;
    cin >> t;
    while (t--) {
        uint32_t in;
        cin >> in;
        cout << a.hammingWeight(in) << "\n";
    }
    return 0;
}
