// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1 || k == 0)
            return 0;

        if (k >= n)
        {
            int ans = 0;
            for (int i = 0; i < n - 1; i++)
                if (prices[i + 1] > prices[i])
                    ans += prices[i + 1] - prices[i];

            return ans;
        }

        int a[k + 1][n], maxDiff;
        for (int i = 0; i <= k; i++)
        {
            maxDiff = -prices[0];
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                    a[i][j] = 0;
                else
                {
                    a[i][j] = max(a[i][j - 1], prices[j] + maxDiff);
                    maxDiff = max(maxDiff, a[i - 1][j] - prices[j]);
                }
            }
        }
        return a[k][n - 1];
    }
};

int main()
{
    Solution a;
    vcetor<int> input = {2, 4, 1};
    cout << a.maxProfit(2, input);
    return 0;
}