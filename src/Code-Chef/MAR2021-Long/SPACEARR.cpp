// Problem Statement: https://www.codechef.com/MARCH21B/problems/SPACEARR/

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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define unmp unordered_map
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

template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (a > b)
        a = b;
    return a;
}

ll MOD = 998244353;

long long fpow(long long base, long long power)
{
    long long result = 1;
    while (power > 0)
    {
        if (power & 1) // Can also use (power & 1) to make code even faster
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}

void dfs(ll s, vector<vector<ll>> &adj, vector<bool> &vis, vector<ll> &arr)
{
    if (vis[s])
        return;
    vis[s] = true;
    arr.pb(s);
    for (auto x : adj[s])
    {
        if (vis[x] == false)
        {
            dfs(x, adj, vis, arr);
        }
    }
}

void bfs(ll x, vector<bool> &vis, vector<vector<ll>> &adlist, vector<ll> &level, vector<ll> &parent)
{
    queue<ll> q;
    vis[x] = true;
    q.push(x);
    while (!q.empty())
    {
        ll s = q.front();
        q.pop();
        // process node s
        for (auto u : adlist[s])
        {
            if (vis[u])
                continue;
            vis[u] = true;
            parent[u] = s;
            level[u] = level[s] + 1;
            q.push(u);
        }
    }
}

void harry()
{
    int n;
    ii(n);
    int ar[n];
    for (int i = 0; i < n; ++i)
        ii(ar[i]);
    sort(ar, ar + n);
    int ans = 0, ok = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (ar[i - 1] > (i))
        {
            ok = 1;
            break;
        }
        else
            ans += i - ar[i - 1];
    }

    if (ans % 2 != 0 and !ok)
        printf("First\n");
    else
        printf("Second\n");
    ravireddy07;
}

int main()
{

    int t;
    scanf("%d", &t);
    while (t--)
        harry();
    return 0;
}
