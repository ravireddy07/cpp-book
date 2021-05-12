// Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        vector<int> left(n), right(n);

        int leftMin = prices[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], prices[i] - leftMin);
            leftMin = min(leftMin, prices[i]);
        }

        int rightMax = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], rightMax - prices[i]);
            rightMax = max(rightMax, prices[i]);
        }

        int profit = right[0];
        for (int i = 1; i < n; i++)
            profit = max(profit, left[i - 1] + right[i]);

        return profit;
    }
};

int main()
{
    Solution a;
    cout << a.maxProfit({3, 3, 5, 0, 0, 3, 1, 4}) << "\n";
    return 0;
}
