// Problem Statement: https://codeforces.com/contest/1473/problem/E

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
#define for1(i, a, b) for (int i = a; i < b; ++i)
#define for2(i, a, b) for (int i = b; i >= a; --i)
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define unmp unordered_map
#define pqi priority_queue<int>
#define pq priority_queue
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
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

const ll inf = 1e18;
void harry()
{
    int n, m;
    ii2(n, m);
    vector<vector<pair<int, int>>> e(n);
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        ii3(u, v, w);
        u--;
        v--;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    vector<ll> dis(4 * n, inf);
    priority_queue<pair<ll, int>> h;
    dis[0] = 0;
    h.emplace(0, 0);
    while (!h.empty())
    {
        ll d = -h.top().first;
        int x = h.top().second;
        h.pop();
        if (d > dis[x])
            continue;
        int u = x / 4;
        int p = x / 2 % 2;
        int q = x % 2;
        for (auto [v, w] : e[u])
        {
            int y = v * 4 + p * 2 + q;
            if (dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                h.emplace(-dis[y], y);
            }
            if (p == 0 && dis[y + 2] > dis[x])
            {
                dis[y + 2] = dis[x];
                h.emplace(-dis[y + 2], y + 2);
            }
            if (q == 0 && dis[y + 1] > dis[x] + 2 * w)
            {
                dis[y + 1] = dis[x] + 2 * w;
                h.emplace(-dis[y + 1], y + 1);
            }
        }
    }
    for (int i = 1; i < n; i++)
        cout << min(dis[i * 4], dis[i * 4 + 3]) << " \n"[i == n - 1];
    ravireddy07;
}

int main()
{
    harry();
    return 0;
}
