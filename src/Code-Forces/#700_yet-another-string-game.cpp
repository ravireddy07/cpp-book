// Problem Statement: https://codeforces.com/contest/1480/problem/A/

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
	string s;
	cin >> s;
	string res = "";
	int k = 0;
	int f = 0, e = 25;
	char ar[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) {
			while (ar[f] == s[i])
				f++;
			res += ar[f];
			f = 0;
		}
		else {
			while (ar[e] == s[i])
				e--;
			res += ar[e];
			e = 25;
		}
	}
	cout << res << "\n";
}

void harry() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i & 1)
			cout << (s[i] == 'z' ? "y" : "z");
		else
			cout << (s[i] == 'a' ? "b" : "a");
	}
	cout << "\n";
	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--)
		harry();
	return 0;
}
