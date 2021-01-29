// Problem Statement: https://www.codeforces.com/contest//problem/E/

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

void harry2() {
	int n, k;
	ii2(n, k);
	ll  ans = 0, sum = 0;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n < 2)
	{
		cout << 0 << endl;
		ravireddy07;
	}
	for (int i = 1; i < n; i++)
	{
		sum += a[i - 1];
		double f = ((double)a[i] * 100) / k;
		if (f <= (double)sum)
			continue;
		else {
			ll f1 = (ll)f;
			if (f == f1)
			{
				ll diff = f1 - sum;
				ans += diff;
				sum = f1;
			}
			else {
				ll diff = f1 - sum + 1;
				ans += diff;
				sum = f1 + 1;
			}
		}
	}
	cout << ans << "\n";
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
