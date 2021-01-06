// Problem Statement: https://codeforces.com/contest/1471/problem/C/

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
#define ill(a) scanf("%lld", &a)
#define ill2(a, b) scanf("%lld%lld", &a, &b)
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
using namespace std;

template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}

void harry()
{
    int n, m;
    ii2(n, m);
    int k[n + 1], c[m + 1];
    for (int i = 1; i <= n; ++i)
        ii(k[i]);
    for (int i = 1; i <= m; ++i)
        ii(c[i]);
    sort(k + 1, k + 1 + n);
    ll ans = 0;
    for (int i = n; i >= 1; --i)
    {
        if (n - i + 1 <= m)
            ans += min(c[k[i]], c[n - i + 1]);
        else
            ans += c[k[i]];
    }

    printf("%lld\n", ans);
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
