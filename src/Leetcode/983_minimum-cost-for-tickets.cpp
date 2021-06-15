// Problem Statement: https://leetcode.com/problems/minimum-cost-for-tickets/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mincostTickets(vector<int> days, vector<int> costs)
    {
        int n = days.size();
        vector<int> dp(n + 1);
        for (int j, i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + costs[0];
            j = distance(days.begin(), upper_bound(days.begin(), days.begin() + i, days[i - 1] - 7));
            dp[i] = min(dp[j] + costs[1], dp[i]);
            j = distance(days.begin(), upper_bound(days.begin(), days.begin() + i, days[i - 1] - 30));
            dp[i] = min(dp[j] + costs[2], dp[i]);
        }
        return dp[n];
    }
};

int main()
{
    Solution a;
    cout << a.mincostTickets({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}, {2, 7, 15}) << "\n";
    return 0;
}
