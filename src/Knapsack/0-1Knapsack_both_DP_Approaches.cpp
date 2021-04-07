#include <bits/stdc++.h>
using namespace std;

int knapsack(int wts[], int prices[], long long int N, long long int w)
{
    if (N == 0 or w == 0)
        return 0;

    int inc = 0, exc = 0;

    if (wts[N - 1] <= w)
        inc = prices[N - 1] + knapsack(wts, prices, N - 1, w - wts[N - 1]);

    exc = 0 + knapsack(wts, prices, N - 1, w);

    return max(inc, exc);
}

int bottomUP(int wts[], int prices[], long long int N, long long int w)
{
    int dp[100][100] = {0};

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || w == 0)
                dp[i][j] = 0;
            else
            {
                int inc = 0, exc = 0;
                if (wts[i - 1] <= w)
                    inc = prices[i - 1] + dp[i - 1][w - wts[i - 1]];
                else
                    exc = dp[i - 1][w];
                dp[i][w] = max(inc, exc);
            }
        }
    }

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= w; j++)
            cout << dp[i][w] << " ";
        cout << "\n";
    }
    return dp[N][w];
}

int main()
{
    long long int N, w;
    cin >> N >> w;
    int wts[N], prices[N];

    for (int i = 0; i < N; ++i)
        cin >> wts[i];
    for (int i = 0; i < N; ++i)
        cin >> prices[i];

    int maxProfit = knapsack(wts, prices, N, w);
    cout << maxProfit << "\n";
    //bottomUP(wts, prices, N, w);
    return 0;
}
