// Problem Statement: https://codeforces.com/contest/1480/problem/D1

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
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> a0(1, -1);
	vector<int> a1(1, -1);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != a0[a0.size() - 1] && a[i] != a1[a1.size() - 1])
		{
			if (i != n && a[i + 1] == a0[a0.size() - 1])
				a0.push_back(a[i]);
			else
				a1.push_back(a[i]);
		}
		else if (a[i] == a0[a0.size() - 1] && a[i] != a1[a1.size() - 1])
			a1.push_back(a[i]);
		else if (a[i] != a0[a0.size() - 1] && a[i] == a1[a1.size() - 1])
			a0.push_back(a[i]);
		else
		{
			ans--;
			a0.push_back(a[i]);
		}
		ans++;
	}
	cout << ans << "\n";
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
