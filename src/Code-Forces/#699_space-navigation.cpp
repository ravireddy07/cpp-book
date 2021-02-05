// Problem Statement: https://codeforces.com/contest/1481/problem/A

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

// Brute force
void harry() {
	int px, py;
	ii2(px, py);
	string s;
	cin >> s;
	int x = 0, y = 0;
	int ans = 0;
	// -3 -5
	// LDLDLDDDR
	if (px == 0)
		ans = 1;
	else if (px < 0) {
		for (int i = 0; i < s.size(); i++) {
			if (x == px) {
				ans = 1;
				break;
			}
			else if (s[i] == 'L') {
				x -= 1;
			}
		}
		if (x == px) {
			ans = 1;
		}
		else
		{
			no;
			ravireddy07;
		}
	}
	else if (px > 0) {
		for (int i = 0; i < s.size(); i++) {
			if (x == px) {
				ans = 1;
				break;
			}
			else if (s[i] == 'R') {
				x += 1;
			}
		}
		if (x == px) {
			ans = 1;
		}
		else
		{
			no;
			ravireddy07;
		}
	}

	if (py == 0)
	{
		yes;
		ravireddy07;
	}
	else if (py < 0) {
		for (int i = 0; i < s.size(); i++) {
			if (y == py) {
				yes;
				ravireddy07;
			}
			else if (s[i] == 'D')
				y -= 1;
		}
		if (y == py) {
			yes;
			ravireddy07;
		}
		else
		{
			no;
			ravireddy07;
		}
	}
	else if (py > 0) {
		for (int i = 0; i < s.size(); i++) {
			if (y == py) {
				yes;
				ravireddy07;
			}
			else if (s[i] == 'U')
				y += 1;
		}
		if (y == py) {
			yes;
			ravireddy07;
		}
		else
		{
			no;
			ravireddy07;
		}
	}
	ravireddy07;
}

void harry() {
	int l = r = u = d = 0;
	int px, py;
	cin >> px >> py;
	string s; cin >> s;
	for (auto c : s) {
		if (c == 'L') l++;
		if (c == 'R') r++;
		if (c == 'U') u++;
		if (c == 'D') d++;
	}

	if ((px > 0) && (px > r))
		no;
	else if ((px < 0) && (-px > l))
		no;
	else if ((py > 0) && (py > u))
		no;
	else if ((py < 0) && (-py > d))
		no;
	else
		yes;
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
