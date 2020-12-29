#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll unsigned long long int


int main() {
  ll t;
  cin>>t;

  ll prime_num[] = {2, 3, 5, 7, 11, 13, 17, 19};
  for(ll i=0;i<t;i++) {
    ll n,result = 0;
    cin>>n;

    for(ll i=0;i<sizeof(prime_num)/sizeof(prime_num[0]);i++) {
      result += n / prime_num[i];
    }

    for(ll i=1;i<(1<<8);i++) {
      ll temp=i,j=0,div=1;
      if(__builtin_popcount(i) > 1) {
        while(temp) {
          (temp & 1) ? div *= prime_num[j] : true;
          temp = temp>>1;
          j++;
        }
        if(__builtin_popcount(i)%2) {
          result += n / div;
        }
        else {
          result -= n/div;
        }
      }
    }
    cout<<result<<endl;
  }
  return 0;
}
