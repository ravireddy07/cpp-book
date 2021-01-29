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

const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;
int c[MAXN], a[MAXN], b[MAXN];
ll f[MAXN];

void harry() {
    int n;
    ii(n);
    for(int i=1; i<=n; ++i) ii(c[i]);
	for(int i=1; i<=n; ++i) ii(a[i]);
	for(int i=1; i<=n; ++i) ii(b[i]);
	
	ll ans = 0;
	f[1] = -linf;
	for(int i=2; i<=n; ++i)
	{
		if(a[i] < b[i]) swap(a[i], b[i]);
		f[i] = c[i]-1 + 2 + (a[i] - b[i]);
		if(a[i] != b[i]) f[i] = max(f[i], f[i-1] - (a[i] - b[i]) + 2 + c[i]-1);
		ans = max(ans, f[i]);
	}
	printf("%lld\n",ans);
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
