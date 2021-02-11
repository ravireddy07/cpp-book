// Problem Statement: https://codeforces.com/contest/1480/problem/D2

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#define ll long long int
#define yes printf("YES\n")
#define no printf("NO\n")
using namespace std;

void harry() {
	int64_t n;
	cin >> n;
	int64_t a[n];
	vector<vector<int64_t>> aa(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		aa[a[i] - 1].push_back(i);
	}
	for (int i = 0; i < n; ++i)
		aa[i].push_back(1000000000000000000);
	vector<int64_t> a0(1, -1);
	vector<int64_t> a1(1, -1);
	int64_t ans = 0;
	vector<int64_t> pr(n, 0);
	for (int i = 0; i < n; ++i)
	{
		pr[a[i] - 1]++;
		if (a[i] != a0[a0.size() - 1] && a[i] != a1[a1.size() - 1])
		{
			ans++;
			if (a0[a0.size() - 1] == -1)
				a0.push_back(a[i]);
			else if (a1[a1.size() - 1] == -1)
				a1.push_back(a[i]);
			else if (aa[a0[a0.size() - 1] - 1][pr[a0[a0.size() - 1] - 1]] < aa[a1[a1.size() - 1] - 1][pr[a1[a1.size() - 1] - 1]])
				a1.push_back(a[i]);
			else
				a0.push_back(a[i]);
		}
		else if (a[i] == a0[a0.size() - 1] && a[i] != a1[a1.size() - 1])
			a0.push_back(a[i]);
		else if (a[i] != a0[a0.size() - 1] && a[i] == a1[a1.size() - 1])
			a1.push_back(a[i]);
		else
			a0.push_back(a[i]);
	}
	cout << ans << "\n";
	ravireddy07;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	harry();
	return 0;
}
