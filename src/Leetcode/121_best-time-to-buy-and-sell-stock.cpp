// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> prices)
    {
        int min_till_now = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < min_till_now)
                min_till_now = prices[i];
            else
                max_profit = max(max_profit, prices[i] - min_till_now);
        }
        return max_profit;
    }
};

int main()
{
    Solution a;
    cout << a.maxProfit({7, 1, 5, 3, 6, 4}) << endl;
    return 0;
}
