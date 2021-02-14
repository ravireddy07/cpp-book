// Problem Statement: https://www.codechef.com/FEB21B/problems/TEAMNAME/

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
#define ill(a) scanf("%lld", &a)
#define ill2(a, b) scanf("%lld%lld", &a, &b)
#define vi vector<int>
#define vc vector<char>
#define vii vector<vector<int>>
#define vcc vector<vector<char>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pb push_back
#define ft first
#define snd second
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define pqi priority_queue<int>
#define pq priority_queue
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

ll getCount(vc sour, vc dest) {
	set<char> s(sour.begin(), sour.end());
	ll cnt = 0;
	for (auto i : dest) {
		if (s.find(i) == s.end())
			continue;
		else
			++cnt;
	}
	return cnt;
}

void harry() {
	ll n;
	ill(n);
	map<string, vc> v;
	string s;

	// Mapping
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (s.size() > 0) {
			// string p = s.substr(1);
			v[s.substr(1)].pb(s[0]);
		}
	}

	ll res = 0, temp;
	for (auto i : v) {
		for (auto j : v) {
			if (i.ft != j.ft) {
				temp = getCount(i.snd, j.snd);
				res += (i.snd.size() - temp) * ((j.snd.size() - temp));
			}
		}
	}

	printf("%lld\n", res);
	ravireddy07;
}


int main(int argc, char const *argv[])
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