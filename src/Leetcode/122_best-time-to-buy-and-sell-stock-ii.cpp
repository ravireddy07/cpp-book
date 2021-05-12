// Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> prices)
    {
        if (prices.empty())
            return 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] - prices[i - 1] > 0)
                profit += (prices[i] - prices[i - 1]);
        return profit;
    }
};

int main()
{
    Solution a;
    cout << a.maxProfit({7, 1, 5, 3, 6, 4}) << "\n";
    return 0;
}
