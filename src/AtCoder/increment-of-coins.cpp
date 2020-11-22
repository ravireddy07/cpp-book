// Problem Statement: https://atcoder.jp/contests/abc184/tasks/abc184_d

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 102;
double dp[MAX][MAX][MAX];

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    dp[a][b][c] = 1;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                if ((i + j + k) == 0)
                    continue;
                dp[i + 1][j][k] += 1.0 * i * dp[i][j][k] / (i + j + k);
                dp[i][j + 1][k] += 1.0 * j * dp[i][j][k] / (i + j + k);
                dp[i][j][k + 1] += 1.0 * k * dp[i][j][k] / (i + j + k);
            }
        }
    }

    double ans = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            ans += (100 + i + j - a - b - c) * (dp[i][j][100] + dp[i][100][j] + dp[100][i][j]);
    cout << setprecision(10) << fixed << ans;
    return 0;
}
