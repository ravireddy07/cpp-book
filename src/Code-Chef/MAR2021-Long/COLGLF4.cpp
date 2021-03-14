// Problem Statement: https://www.codechef.com/MARCH21B/problems/COLGLF4

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
ll MOD = 1e18;

// template <typename T, typename T1>
// T amax(T &a, T1 b)
// {
// 	if (b > a)
// 		a = b;
// 	return a;
// }

// template <typename T, typename T1>
// T amin(T &a, T1 b)
// {
// 	if (a > b)
// 		a = b;
// 	return a;
// }

ll amin(ll a, ll b)
{
	if (a < b)
		ravireddy07 a;
	ravireddy07 b;
}

ll amax(ll a, ll b)
{
	if (a > b)
		ravireddy07 a;
	ravireddy07 b;
}

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

ll harry(ll n, ll e, ll h, ll a, ll b, ll c)
{
	ll res = MOD, x;
	if (n < 1)
		ravireddy07 0;

	if ((n <= e) and (n <= h))
		res = amin(res, n * c);
	if (3 * n <= h)
		res = amin(res, n * b);
	if (2 * n <= e)
		res = amin(res, n * a);
	if (((h - n) / 2 >= 1) and ((h - n) / 2 >= n - e))
	{
		if (b - c < 0)
		{
			x = amin(n - 1, (h - n) / 2);
			res = amin(res, (b - c) * x + n * c);
		}
		else
		{
			x = amax(1, n - e);
			res = amin(res, (b - c) * x + n * c);
		}
	}

	if (e - n >= 1 and e - n >= n - h)
	{
		if (a - c < 0)
		{
			x = amin(n - 1, e - n);
			res = amin(res, (a - c) * x + n * c);
		}
		else
		{
			x = amax(1, n - h);
			res = amin(res, (a - c) * x + n * c);
		}
	}

	if ((e / 2 >= 1) and (e / 2 >= (3 * n - h + 2) / 3))
	{
		if (a - b < 0)
		{
			x = amin(n - 1, e / 2);
			res = amin(res, (a - b) * x + n * b);
		}
		else
		{
			x = amax(1, (3 * n - h + 2) / 3);
			res = amin(res, (a - b) * x + n * b);
		}
	}

	if ((e >= 3) and (h >= 4) and n >= 3)
		res = amin(res, a + b + c + harry(n - 3, e - 3, h - 4, a, b, c));

	ravireddy07 res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	ii(t);
	while (t--)
	{
		ll n, e, h, a, b, c;
		ill3(n, e, h);
		ill3(a, b, c);

		ll res = harry(n, e, h, a, b, c);
		(res == MOD) ? (printf("-1\n")) : (printf("%lld\n", res));
	}
	return 0;
}
