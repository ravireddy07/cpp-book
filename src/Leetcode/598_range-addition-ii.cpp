// Problem Statement:  https://leetcode.com/problems/range-addition-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> ops)
    {
        int r = INT_MAX, c = INT_MAX;
        int len = ops.size();
        if (len == 0)
            return (m * n);
        for (int i = 0; i < len; i++)
        {
            r = min(r, ops[i][0]);
            c = min(c, ops[i][1]);
        }
        return (r * c);
    }
};

int main()
{
    Solution a;
    cout << a.maxCount(3, 3, {{2, 2}, {2, 2}}) << "\n";
    return 0;
}
