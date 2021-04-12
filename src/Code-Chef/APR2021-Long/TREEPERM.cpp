// Problem Statement: https://www.codechef.com/APRIL21B/problems/TREEPERM

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
const int MOD = (int)1e9 + 7;

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

        if (power & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        //power >> = 1;
        power = power / 2;
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

const int M = 1000003;

long long ans;
int A[100005], B[100005];
long long P[1000006];

vector<int> X[100005];
pair<long long, long long> Z[100005];

void harry(int x, int par)
{
    int flag = 0;
    Z[x] = {P[A[x]], P[B[x]]};

    for (auto y : X[x])
        if (y != par)
        {
            harry(y, x);

            if (Z[y].first == Z[y].second)
                continue;

            if (flag == 1)
                ans = 0;

            flag = 1;
            Z[x].first += Z[y].first;
            Z[x].second += Z[y].second;
        }

    int children = X[x].size() - (par != 0);

    if (flag == 0)
        ans = ans * (children + 1) % MOD;

    if (par == 0 && Z[x].first != Z[x].second)
        ans = 0;
    ravireddy07;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    ii(t);
    P[0] = 1;

    for (int i = 1; i <= 1000000; i++)
        P[i] = P[i - 1] * M % MOD;

    while (t--)
    {
        int n, s;
        cin >> n >> s;

        for (int i = 1; i <= n; i++)
            X[i].clear();

        for (int i = 1; i <= n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            X[u].push_back(v);
            X[v].push_back(u);
        }

        for (int i = 1; i <= n; i++)
            cin >> A[i];

        for (int i = 1; i <= n; i++)
            cin >> B[i];

        ans = 1;
        harry(1, 0);

        if (s == 1)
            ans = min(ans, 1LL);

        cout << ans << "\n";
    }
    return 0;
}
