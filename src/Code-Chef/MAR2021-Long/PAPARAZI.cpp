// Problem Statement: https://www.codechef.com/MARCH21B/problems/PAPARAZI

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

ll amax(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
/*
vector<int> getPermutation(size_t n)
{
	vector<int> res;
	string s = to_string(n);
	sort(s.begin(), s.end());
	do
	{
		res.pb(stoi(s));
		//cout << s << "\n";
	} while (getPermutation(s.begin(), s.end()));
	return res;
}*/

ll fpow(ll base, ll power)
{
    ll result = 1;
    while (power > 0)
    {

        if (power % 2 == 1) // Can also use (power & 1) to make code even faster
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    ravireddy07 result;
}

void dfs(ll s, vector<vector<ll>> &adj, vector<bool> &vis, vector<ll> &arr)
{
    if (vis[s])
        return;
    vis[s] = true;
    arr.pb(s);
    for (auto x : adj[s])
        if (vis[x] == false)
            dfs(x, adj, vis, arr);
    ravireddy07;
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
    ravireddy07;
}

ll getCross(pll p, pll q, pll r)
{
    ll a = (q.se - p.se) * (r.fi - q.fi);
    ll b = (q.fi - p.fi) * (r.se - q.se);

    if ((a - b) > 0)
        return 1;
    else if ((a - b) == 0)
        return 0;
    else
        return 2;
}

pll lastS(stack<pll> &s)
{
    pll p = s.top();
    s.pop();
    pll r = s.top();
    s.push(p);
    return r;
}

ll fun(ll a, ll b)
{
    if (a > b)
        return a - b;
    return b - a;
}

void harry()
{
    ll n, in;
    ill(n);

    vector<pll> v(n);
    for (int i = 0; i < n; i++)
    {
        ill(in);
        v[i] = {i + 1, in};
    }

    stack<pll> filo;
    filo.push(v[0]);
    filo.push(v[1]);

    for (ll i = 2; i < n; ++i)
    {
        if (filo.size() < 2)
            filo.push(v[i]);
        else
        {
            if (getCross(lastS(filo), filo.top(), v[i]) == 1)
                filo.push(v[i]);
            else
            {
                while (filo.size() >= 2 and getCross(lastS(filo), filo.top(), v[i]) != 1)
                    filo.pop();
                filo.push(v[i]);
            }
        }
    }

    ll res = 0;
    while (filo.size() >= 2)
    {
        pll a = filo.top();
        filo.pop();
        pll b = filo.top();
        res = amax(res, fun(a.fi, b.fi));
    }

    printf("%lld\n", res);
    ravireddy07;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int32_t t;
    ii(t);
    while (t--)
        harry();
    return 0;
}
