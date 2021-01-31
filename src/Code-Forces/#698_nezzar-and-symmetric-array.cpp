// Problem Statement: https://codeforces.com/contest/1478/problem/C/

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

// Unfinished Solution
// d[i] = sum(abs(a[i]-a[j]))
void harry()
{
	int n;
	ii(n);
	int d[2 * n];
	for (int i = 0; i < 2 * n; i++) {
		ii(d[i]);
	}
	int a[] = {1, -3, -1, 3}, sum;
	bool ok = 0;
	int sumd[2 * n];
	for (int i = 0; i < 2 * n; ++i) {
		sum = 0;
		// a={1,-3,-1,3}
		for (int j = 0; j < 2 * n; j++) {
			sum += abs(a[i] - a[j]);
		}
		sumd[i] = sum;
		cout << sum << " ";
		//if(sum == d[i]) ok=1;
	}
	cout << endl;
	(ok ? yes : no);
	ravireddy07;
}

// Accepted Solution
void harry() {
	int n;
	ii(n);
	map<ll, int> ms;
	bool bisa = 1;
	vl num;
	ll x, bigger, temp;

	for (int i = 0; i < 2 * n; i++)
	{
		ill(x);
		num.pb(x);
		if (x % 2)
			bisa = 0;
		ms[x]++;
	}

	for (auto x : ms)
		if (x.second % 2 || x.second > 2)
			bisa = 0;

	sorta(num);
	bigger = 0;
	for (int i = 2 * n - 1; i >= 0; i -= 2) {
		temp = num[i];
		temp -= 2 * bigger;
		if (temp % (i + 1))
			bisa = 0;
		temp /= (i + 1);
		if (temp <= 0)
			bisa = 0;
		bigger += temp;
	}
	(bisa) ? yes : no;
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
