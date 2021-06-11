// https://leetcode.com/problems/minimum-operations-to-make-array-equal/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; i = i + 2)
        {
            ans = ans + (n - i);
        }
        return ans;
    }
};

int main()
{
    Solution a;
    cout << a.minOperations(3) << endl;
    return 0;
}
