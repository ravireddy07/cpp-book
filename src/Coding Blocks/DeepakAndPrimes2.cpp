#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define ll long long int

int main() {
	int t;
	cin>>t;
	for(int h=0;h<t;h++) {
		ll a,b;
		cin>>a>>b;
		ll pp[1000000];
		fill(pp,pp+1000000,1);
		ll n=sqrt(b);
		ll p[n+1];
		fill(p,p+n+1,1);

		for(ll i=2;i*i*i*i<=b;i++){
			if(p[i]){
				for(ll j=2*i;j*j<=b;j+=i) {
					p[j]=0;
				}
		  }
		}

		for(ll i=2;i*i<=b;i++){
			if(p[i]) {
				for(ll j=a;j<=b;) {
					if(j>i&&j%i==0) {
						pp[j-a]=0;
						j+=i;
					}
					else
						j++;
				}
			}
		}

		ll x=(a==1)?2:a;
		for(ll i=x;i<=b;i++) {
			if(pp[i-a])
			cout<<i<<endl;
		}
		if(t!=0)
			cout<<endl;
	}
	return 0;
}
