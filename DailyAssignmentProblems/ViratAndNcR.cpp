#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll FindPower(ll a, ll b, ll lar) {
	ll res = 1;
	a = a % lar;
	while(b>0) {
		if (b & 1)
			res = (res*a) % lar;
		b = b>>1;
		a = (a*a) % lar;
	}
	return res;
}

ll FindInverse(ll n, ll lar) {
	return FindPower(n, lar-2, lar);
}

ll NcR(ll n, ll r, ll lar) {
	if(r==0) {
		return 1;
	}
	ll arr[n+1];
	arr[0] = 1;
	for (ll i=1 ; i<=n; i++)
		arr[i] = arr[i-1]*i%lar;
	ll FinalResult = (arr[n]*FindInverse(arr[r], lar)%lar*FindInverse(arr[n-r], lar) % lar) % lar;
	return FinalResult;
}

int main() {
	ll n,r,lar=1000000007;
	cin>>n>>r;
	cout<<NcR(n, r, lar);
	return 0;
}
