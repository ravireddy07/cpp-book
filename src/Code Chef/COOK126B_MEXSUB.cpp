// Problem Statement: https://www.codechef.com/COOK126B/status/MEXSUB

#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 1e9+10
#define INFL 1e18
#define mod 1000000007
using namespace std;

ll power(ll x, ll n) {ll res = 1; while (n > 0) {if (n % 2 == 1) {res = res * x;} x = x * x; n = n / 2;} return res;}
ll powm(ll a, ll b) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		int n, i, j;
		cin >> n;
		int a[n + 1];
		set<int>s;
		for (i = 0; i <= n + 5; i++)
			s.insert(i);
		for (i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (s.find(a[i]) != s.end())
			{
				s.erase(a[i]);
			}
		}
		int x = *s.lower_bound(-1);
		if (x == 0)
		{
			cout << powm(2, n - 1) << "\n";
			continue;

		}
		ll dp[n + 1] = {0};
		map<int, int>m;
		dp[0] = 1;
		ll l = 1;
		for (i = 1; i <= n; i++)
		{
			if (a[i] < x)
				m[a[i]]++;
			if (m.size() == x)
			{
				dp[i] = 1;
				m.clear();
				break;
			}
		}


		i++;
		l = i;
		int f = 0;
		for (; i <= n; i++)
		{
			if (a[i] < x)
				m[a[i]]++;
			dp[i] = dp[i - 1];
			if (m.size() == x)
			{
				while (1)
				{
					if (a[l] > x)
					{
						dp[i] += dp[l];
						dp[i] %= mod;

						l++;
						continue;
					}
					if (m[a[l]] == 1)
					{
						if (f == 0)
						{
							f = 1;
							dp[i] += dp[l - 1];
							dp[i] %= mod;
						}
						break;
					}
					else
					{
						dp[i] += dp[l];
						dp[i] %= mod;
						m[a[l]]--;
						l++;

					}
				}
			}
		}
		cout << dp[n] << "\n";
	}
}