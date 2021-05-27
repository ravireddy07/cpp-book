// Problem Statement: https://leetcode.com/problems/nim-game/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canWinNim(int n)
    {
        return n % 4 != 0;
    }
};

int main()
{
    Solution a;
    cout << a.canWinNim(4) << "\n";
    return 0;
}
