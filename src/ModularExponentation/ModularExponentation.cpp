#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll PowerExp(ll a, ll b, ll c)
{
	ll result = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			result = result * a;
			result = result % c;
			result = (result + c) % c;
			a = a * a;
			a = a % c;
			b = b >> 1;
		}
		return result % c;
	}
}

ll ModularExp(ll a, ll b, ll c)
{
	return (PowerExp(a, b, c) % c);
}

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	cout << ModularExp(a, b, c);
	return 0;
}
