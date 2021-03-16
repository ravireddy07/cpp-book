// Problem Statement: https://www.codechef.com/MARCH21B/problems/IRSTXOR

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
ll MOD = 998244353;

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

// vector<int> getPermutation(size_t n)
// {
//     vector<int> res;
//     string s = to_string(n);
//     sort(s.begin(), s.end());
//     do
//     {
//         res.pb(stoi(s));
//     } while (getPermutation(s.begin(), s.end()));
//     return res;
// }

long long fpow(long long base, long long power)
{
    long long result = 1;
    while (power > 0)
    {

        if (power % 2 == 1) // Can also use (power & 1) to make code even faster
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
    long int n;
    cin >> n;
    long int a = 0, cnt = 0;
    while (n >= a)
    {
        a = pow(2, cnt);
        ++cnt;
    }
    long int ans = pow(2, cnt - 2) - 1;
    cout << ans * (ans + a - n) << "\n";
    ravireddy07;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    while (t--)
        harry();
    return 0;
}
