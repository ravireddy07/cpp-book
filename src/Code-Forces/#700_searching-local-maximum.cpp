// Problem Statement: https://codeforces.com/contest/1480/problem/C/

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

	int z;
	if (n <= 100)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << "? " << i << "\n";
			cin >> z;
			if (z == 1) { cout << "! " << i << "\n"; return; }
		}
	}

	int x = 1, y = n;
	while (1)
	{
		int a, b, c;

		if (x + 1 == y)
		{
			cout << "? " << x << "\n";
			cin >> a;
			cout << "? " << y << "\n";
			cin >> b;

			if (a < b)
				cout << "! " << x << "\n";
			else
				cout << "! " << y << "\n";

			return;
		}

		int mid = (x + y) / 2;
		cout << "? " << mid - 1 << "\n";
		cin >> a;
		cout << "? " << mid << "\n";
		cin >> b;
		cout << "? " << mid + 1 << "\n";
		cin >> c;

		if (b < c && b < a)
		{
			cout << "! " << mid << "\n";
			return;
		}

		if (a < b)
			y = mid;
		else
			x = mid;
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
	return 0;
}
