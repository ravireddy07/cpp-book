// Problem Statement: https://www.codechef.com/COOK126B/problems/EQLGIFTS

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, int> pli;
#define N 100100
#define M 50005000

int n, a[N], pw[20];
int lb[M], nb[M];
ll dp[M];
const int D = 28;
vector <pli> vec;

char s[N];

int main() {
	pw[0] = 1;
	for (int i = 1; i < 20; i ++) pw[i] = 3 * pw[i - 1];
	for (int i = 1; i < M; i ++) {
		int c = 0, j;
		for (j = i; j % 3 == 0; j /= 3, c ++);
		lb[i] = c, nb[i] = j % 3;
	}
	int T;
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
		int m = min(n, D);
		bool fg = true;

		int A = m >> 1, B = m - A, up = pw[A], x, y;

		vec.clear(); vec.reserve(up); vec.emplace_back(0, 0);
		for (int i = 1; i < up; i ++) {
			int c = lb[i];
			if (nb[i] == 1) dp[i] = dp[i - pw[c]] + a[c];
			else dp[i] = dp[i - 2 * pw[c]] - a[c];
			vec.emplace_back(dp[i], i);
			if (dp[i] == 0) {
				fg = false;
				x = i, y = 0;
				break;
			}
		}
		sort(vec.begin(), vec.end());

		if (fg) {
			up = pw[B];
			for (int i = 1; i < up; i ++) {
				int c = lb[i];
				if (nb[i] == 1) dp[i] = dp[i - pw[c]] + a[c + A];
				else dp[i] = dp[i - 2 * pw[c]] - a[c + A];
				auto it = lower_bound(vec.begin(), vec.end(), pli(dp[i], 0));
				if (it -> first == dp[i]) {
					fg = false;
					x = it -> second, y = i;
					break;
				}
			}
		}


		if (fg) puts("NO");
		else {
			for (int i = 0; i < n; i ++) s[i] = 'N'; s[n] = 0;
			for (int i = 0; i < 16; i ++) {
				int xx = x % 3, yy = y % 3; x /= 3, y /= 3;
				if (xx == 1) s[i] = 'A';
				else if (xx == 2) s[i] = 'B';
				if (yy == 1) s[i + A] = 'B';
				else if (yy == 2) s[i + A] = 'A';

			}
			puts("YES");
			puts(s);
		}
	}
	return 0;
}
