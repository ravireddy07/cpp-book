// Problem Statement: https://www.codechef.com/JAN21B/problems/BLKJK/

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#define ll long long int
#define ravireddy07 return
#define ii(a) scanf("%d", &a)
#define ii2(a, b) scanf("%d%d", &a, &b)
#define ii3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ill(a) scanf("%lld", &a)
#define ill2(a, b) scanf("%lld%lld", &a, &b)
#define ill3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define Pii pair<int, int>
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define pqi priority_queue<int>
#define pq priority_queue
#define yes printf("YES\n")
#define no printf("NO\n")
#define mod 998244353
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}

void harry()
{
    int n, x, y;
    ii3(n, x, y);
    vi a(n);
    for (int i = 0; i < n; i++)
        ii(a[i]);
    int ans = n;
    vector<vi> pre(n + 1, vi(y + 1, n)), suf(pre);
    pre[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            pre[i + 1][j] = std::min(pre[i + 1][j], pre[i][j] + 1);
            if (j >= a[i])
                pre[i + 1][j] = std::min(pre[i + 1][j], pre[i][j - a[i]]);
        }
    }
    suf[n][0] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= y; j++)
        {
            suf[i][j] = std::min(suf[i][j], suf[i + 1][j]);
            if (j >= a[i])
                suf[i][j] = std::min(suf[i][j], suf[i + 1][j - a[i]] + 1);
        }
    }
    for (int i = 0; i <= n; i++)
    {
        deque<int> que;
        for (int j = 0, k = y; j <= y; j++)
        {
            while (k >= 0 && j + k >= x)
            {
                while (!que.empty() && suf[i][k] < suf[i][que.back()])
                    que.pop_back();
                que.push_back(k);
                k--;
            }
            while (!que.empty() && j + que.front() > y)
                que.pop_front();
            assert(!que.empty());
            ans = std::min(ans, std::max(pre[i][j], suf[i][que.front()]));
        }
    }
    if (ans >= n)
        ans = -1;
    printf("%d\n", ans);
    ravireddy07;
}

int main()
{
    int t;
    ii(t);
    while (t--)
        harry();
    return 0;
}
