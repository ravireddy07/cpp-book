// Problem Statement: https://leetcode.com/problems/implement-rand10-using-rand7/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rand10()
    {
        int random = 0;
        for (int i = 0; i < 7; i++)
            random += rand7();
        return random % 10 + 1;
    }
};

int main()
{
    Solution a;
    cout << rand10() << "\n";
    return 0;
}
