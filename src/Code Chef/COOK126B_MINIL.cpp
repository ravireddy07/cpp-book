// Problem Statement: https://www.codechef.com/COOK126B/problems/MINIL

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

void harry() {
	ll n, m;
	ill2(n, m);
	string a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	string temp1[n], temp2[n];
	bool flag = 1;
	for (int i = 0; i < n; i += 2)
	{
		flag = 1;
		for (int j = 0; j < m; j++)
		{
			if (flag)
			{
				temp1[i][j] = '.';
				temp2[i][j] = '*';
				flag = 0;
			}
			else
			{
				temp1[i][j] = '*';
				temp2[i][j] = '.';
				flag = 1;
			}
		}
	}

	flag = 0;
	for (int i = 1; i < n; i += 2)
	{
		flag = 0;
		for (int j = 0; j < m; j++)
		{
			if (flag)
			{
				temp1[i][j] = '.';
				temp2[i][j] = '*';
				flag = 0;
			}
			else
			{
				temp1[i][j] = '*';
				temp2[i][j] = '.';
				flag = 1;
			}
		}
	}

	ll count1 = 0, count2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != temp1[i][j])
				count1++;
			if (a[i][j] != temp2[i][j])
				count2++;
		}
	}

	printf("%lld\n", ((n % 2 != 0 && m % 2 != 0) ? count2 : min(count1, count2)));
	ravireddy07;
}

int main()
{
	ll t;
	ill(t);
	while (t--)
		harry();
	return 0;
}
