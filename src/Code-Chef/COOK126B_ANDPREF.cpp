// Problem Statement: https://www.codechef.com/COOK126B/problems/ANDPREF

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;

ll binpow(ll a, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) {
			(res *= a) %= mod;
		}
		p >>= 1;
		(a *= a) %= mod;
	}
	return res;
}

void harry() {
	int n;
	cin >> n;
	int m = 1;
	while ((1 << m) < n) {
		m++;
	}

	vector<vector<int>> layers(m + 1);
	int topkek = 1 << m;
	for (int mask = 0; mask < topkek; mask++) {
		layers[__builtin_popcount(mask)].push_back(mask);
	}
	vector<ll> cnt(topkek), dp(topkek);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	for (int i = 0; i < m; i++) {
		for (int mask = 0; mask < topkek; mask++) {
			if (!(mask >> i & 1)) {
				cnt[mask] += cnt[mask | (1 << i)];
			}
		}
	}

	dp[topkek - 1] = cnt[topkek - 1] * (topkek - 1);
	for (int i = m - 1; i >= 0; i--) {
		for (int mask : layers[i]) {
			ll best = 0;
			for (int j = 0; j < m; j++) {
				if (!(mask >> j & 1)) {
					best = max(best, dp[mask | (1 << j)] + (cnt[mask] - cnt[mask | (1 << j)]) * mask);
				}
			}
			dp[mask] = best;
		}
	}

	cout << dp[0] << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--)
		harry();
	return 0;
}