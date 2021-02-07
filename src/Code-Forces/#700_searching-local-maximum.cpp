// Problem Statement: https://codeforces.com/contest/1480/problem/C/

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

void harry() {
	int n;
	cin >> n;

	int z;
	if (n <= 100)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << "? " << i << "\n";
			cin >> z;
			if (z == 1) { cout << "! " << i << "\n"; return; }
		}
	}

	int x = 1, y = n;
	while (1)
	{
		int a, b, c;

		if (x + 1 == y)
		{
			cout << "? " << x << "\n";
			cin >> a;
			cout << "? " << y << "\n";
			cin >> b;

			if (a < b)
				cout << "! " << x << "\n";
			else
				cout << "! " << y << "\n";

			return;
		}

		int mid = (x + y) / 2;
		cout << "? " << mid - 1 << "\n";
		cin >> a;
		cout << "? " << mid << "\n";
		cin >> b;
		cout << "? " << mid + 1 << "\n";
		cin >> c;

		if (b < c && b < a)
		{
			cout << "! " << mid << "\n";
			return;
		}

		if (a < b)
			y = mid;
		else
			x = mid;
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
