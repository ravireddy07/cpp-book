#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int

void SetValues(ll f[]) {
  f[0] = 0;
	f[1] = 1;
  for(ll i=2;i<300;i++)
		f[i] = (f[i-1] + f[i-2])%100;
}

int N_Fibbnaci(ll f[], int n) {
	return f[n%300];
}

int main() {
  ll f[300] = {0};
  SetValues(f);

  ll n;
  cin>>n;
	cout<<N_Fibbnaci(f, n)<<endl;

  return 0; 
}
