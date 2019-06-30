#include<iostream>
using namespace std;

#define ll long long int

int main() {
	ll q;
	cin>>q;
	while(q--) {
		ll n;
		cin>>n;
		ll sume=0,sumo=0;
		for(ll i=2;i*i<=n;i++) {
			if(n%i==0) {
				if(i%2==0){sume+=i;}
				else sumo+=i;

				ll temp=n/i;
				if(temp!=i)
				{
				if(temp%i==0){sume+=temp;}
				else sumo+=temp;
				}
				}
			}
			if(n%2==0)sume+=n;
			else sumo+=n;
			sumo++;
			cout<<sume-sumo<<endl;
		}
	return 0;
}
