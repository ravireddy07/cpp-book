// Problem Statement: https://codeforces.com/contest/1476/problem/D/

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

const int Maxn = 300005;
int n;
char str[Maxn];
int L1[Maxn], L2[Maxn];
int R1[Maxn], R2[Maxn];

void harry() {
	ii(n);
	scanf("%s", str);
	for (int i = 0; i <= n; i++)
	{
		L1[i] = str[i] == 'L' ? 1 + (i > 0 ? L2[i - 1] : 0) : 0;
		L2[i] = str[i] == 'R' ? 1 + (i > 0 ? L1[i - 1] : 0) : 0;
	}
	for (int i = n; i >= 0; i--) {
		R1[i] = str[i] == 'L' ? 1 + (i < n ? R2[i + 1] : 0) : 0;
		R2[i] = str[i] == 'R' ? 1 + (i < n ? R1[i + 1] : 0) : 0;
	}
	for (int i = 0; i <= n; i++) {
		int ans = 1;
		if (i > 0) ans += L1[i - 1];
		ans += R2[i];
		printf("%d%c", ans, i + 1 <= n ? ' ' : '\n');
	}
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
