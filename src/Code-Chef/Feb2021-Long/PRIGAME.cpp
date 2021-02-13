// Problem Statement: https://www.codechef.com/FEB21B/problems/PRIGAME/

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


const int maxx = 1e6 + 5;
int allPrimes[maxx];

void setup()
{
	vi tempStr;
	bool fPrimes[maxx];
	// bool fPrimes[maxx] = {true};
	memset(fPrimes, true, sizeof(fPrimes));

	for (int i = 2; i * i < maxx; ++i)
		if (fPrimes[i] == true)
			for (int j = i * i; j < maxx; j += i)
				fPrimes[j] = false;

	for (int i = 2; i < maxx; ++i)
		if (fPrimes[i])
			tempStr.pb(i);

	auto it = tempStr.begin();
	int cnt = 0;
	for (int i = 0; i < maxx; ++i)
	{
		if (*it <= i)
		{
			++cnt;
			++it;
		}
		allPrimes[i] = cnt;
	}
	ravireddy07;
}


void harry() {
	int x, y;
	ii2(x, y);
	if (allPrimes[x] <= y) {
		printf("Chef\n");
		ravireddy07;
	}
	printf("Divyam\n");
	ravireddy07;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	setup();
	int t;
	ii(t);
	while (t--)
		harry();
	return 0;
}
