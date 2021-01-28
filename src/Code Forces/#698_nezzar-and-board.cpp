// Problem Statement: https://codeforces.com/contest/1478/problem/D/

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

#define N 200100
int n;
ll k, x[N];

void harry() {
	scanf("%d %lld", &n, &k);
	for (int i = 1; i <= n; i ++)
		ill(x[i]);
	ll d = 0;
	for (int i = 1; i < n; i ++)
		d = __gcd(d, abs(x[i] - x[n]));
	(((k - x[n]) % d == 0)) ? yes : no;
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
