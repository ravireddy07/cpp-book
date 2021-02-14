// Problem Statement: https://www.codechef.com/FEB21B/problems/MULGAME/

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
#define f first
#define s second
#define pii pair<int, int>
#define unmp unordered_map
#define pqi priority_queue<int>
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

const int maxx = 1000001;

void harry() {
	int n, q, m;
	ii3(n, q, m);

	int ar[n];
	for1(i, 0, n)
	ii(ar[i]);

	int dp[maxx] = {};
	map<pii, int>mp;

	while (q--)
	{
		int l, r;
		ii2(l, r);
		--l, --r;

		if (ar[l] > m)
			continue;
		else if (ar[l] <= m and ar[r] > m)
			++dp[ar[l]], --dp[m + 1];
		else if (ar[r] <= m)
		{
			++dp[ar[l]], --dp[m + 1];
			++mp[ {ar[l], ar[r]}];
		}
	}

	for (auto x : mp)
	{
		int k = x.f.f, p = x.f.s, l = x.s;
		int c = p + 2 * k;

		dp[p + k] -= l;
		dp[p + 2 * k] += l;

		while (c + p <= m)
		{
			c += p;
			dp[c] -= l;
			dp[c + k] += l;
			c += k;
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		dp[i] += dp[i - 1];
		ans = amax(ans, dp[i]);
	}
	printf("%d\n", ans);
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
	while (t--)
		harry();
	return 0;
}
