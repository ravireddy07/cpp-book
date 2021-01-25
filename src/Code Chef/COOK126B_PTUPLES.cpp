// Problem Statement: https://www.codechef.com/COOK126B/problems/PTUPLES

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

/*

1 2 3
0

2 3 5
1

2 3 5 7 11 13 17 19

*/
const ll cnt = 1000010;
ll prime[cnt] = {0};
ll storeRes[cnt];

void harry() {
	for (ll i = 2; i * i <= cnt; i++)
		if (prime[i] == 0)
			for (ll j = i * i; j <= cnt; j += i)
				prime[j] = 1;

	storeRes[0] = 0;
	storeRes[1] = 0;
	storeRes[2] = 0;
	storeRes[3] = 0;
	for (ll i = 4; i <= cnt; i++)
	{
		if (prime[i] == 0 && prime[i - 2] == 0)
			storeRes[i] = storeRes[i - 1] + 1;
		else
			storeRes[i] = storeRes[i - 1];
	}
	ravireddy07;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	harry();
	int t;
	ii(t);
	ll n;
	while (t--) {
		ill(n);
		printf("%lld\n", storeRes[n]);
	}
	return 0;
}
