// Problem Statement:  https://codeforces.com/contest/1474/problem/D/

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
#define pii pair<int,int>
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

const int MX = 200005;
int n, a[MX], pre[MX], suf[MX];

void harry() {
	ii(n);
	for (int i = 1; i <= n; i++)
		ii(a[i]);

	for (int i = 1; i <= n; i++) {
		if (pre[i - 1] == -1) pre[i] = -1;
		else {
			pre[i] = a[i] - pre[i - 1];
			if (pre[i] < 0)
				pre[i] = -1;
		}
	}

	if (pre[n] == 0) {
		yes;
		return;
	}

	suf[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		if (suf[i + 1] == -1) suf[i] = -1;
		else {
			suf[i] = a[i] - suf[i + 1];
			if (suf[i] < 0)
				suf[i] = -1;
		}
	}

	for (int i = 1; i + 1 <= n; i++) {
		if (pre[i - 1] == -1 || suf[i + 2] == -1) continue;

		vi v = {pre[i - 1], a[i + 1], a[i], suf[i + 2]};

		for (int i = 1; i < 4; i++) {
			if (v[i - 1] == -1) v[i] = -1;
			else {
				v[i] -= v[i - 1];
				if (v[i] < 0)
					v[i] = -1;
			}
		}

		if (v[3] == 0) {
			yes;
			return;
		}
	}

	no;
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