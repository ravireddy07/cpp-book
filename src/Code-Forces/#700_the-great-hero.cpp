// Problem Statement: https://codeforces.com/contest/1480/problem/B/

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

// Solution 1
void harry() {
	int a, b, n;
	ii3(a, b, n);
	vector<int> ar, br;
	int in;
	for (int i = 0; i < n; i++) {
		ii(in);
		ar.pb(in);
	}
	for (int i = 0; i < n; i++) {
		ii(in);
		br.pb(in);
	}

	pq<pii, vector<pii>, greater<pii>> stru;
	for (int i = 0; i < n; i++) {
		stru.push({ar[i], br[i]});
	}

	bool ok = 0;

	for (int i = 0; i < n; i++) {
		pii tar = stru.top();
		stru.pop();
		int Acnt = tar.first, Hcnt = tar.second;

		while (b > 0 and Hcnt > 0) {
			b -= Acnt;
			Hcnt -= a;
		}

		if (b <= 0) {
			if (Hcnt <= 0) {
				if (i == n - 1)
					break;
			}
			else {
				no;
				ok = 1;
				break;
			}
		}
	}
	if (!ok)
		yes;
	ravireddy07;
}

// Solution 2
void harry() {
	int A, B, n;
	cin >> A >> B >> n;
	int a[n], b[n];
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

	long long tot = 0;
	for (int i = 1; i <= n; i++) {
		int t = b[i] / A + (b[i] % A > 0);
		tot += 1LL * t * a[i];
	}
	int mx = 0;
	for (int i = 1; i <= n; i++)
		mx = max(mx, a[i]);

	if (tot - mx < B)
		yes;
	else
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
