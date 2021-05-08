// Problem Statement: https://leetcode.com/problems/wildcard-matching/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string a, string b)
    {
        int n = a.size(), m = b.size(), i, j;
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;

        for (j = 1; j <= m; j++)
        {
            if (b[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                if (b[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else if (b[j - 1] == '?' || a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[n][m];
    }
};

int main()
{
    Solution a;
    cout << a.isMatch("aa", "a") << "\n";
    return 0;
}
