#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ul unsigned

vector<bool>FindPrime(10000000,true);
ul Array[10000000];

void PrateekCandy() {
  FindPrime[0]=FindPrime[1]=false;
  for(ul i=2;i*i<=10000000;i++) {
    if(FindPrime[i]) {
      for(ul j=i;j*i<=10000000;j++) {
        FindPrime[i*j]=false;
      }
    }
  }
  ul var1 = 1;
  Array[0]=2;

  for(int i=3;i<=10000000;i+=2) {
    if(FindPrime[i]) {
      Array[var1++]=i;
    }
  }
}

int main() {
  ll t;
  cin>>t;
  PrateekCandy();
  for(ll i=0;i<t;i++) {
    ll n;
    cin>>n;
    cout<<Array[n-1]<<endl;
  }
  return 0;
}
