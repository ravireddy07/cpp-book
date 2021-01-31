// Problem Statement: https://codeforces.com/contest/1437/problem/C/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 422;
const int INF = (int)1e8;

int n;
int a[N];
int dp[N][N];

int test()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);
    int l = -1, r = INF;

    for (int i = 0; i <= n; i++)
        for (int x = 0; x <= 2 * n; x++)
            dp[i][x] = INF;

    dp[0][0] = 0;

    for (int i = 0; i <= n; i++)
        for (int x = 0; x < 2 * n; x++)
        {
            dp[i][x + 1] = min(dp[i][x + 1], dp[i][x]);
            if (i < n)
                dp[i + 1][x + 1] = min(dp[i + 1][x + 1], dp[i][x] + abs(a[i] - (x + 1)));
        }

    printf("%d\n", dp[n][2 * n]);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        test();
    return 0;
}
