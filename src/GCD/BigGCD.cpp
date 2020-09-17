#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll Fun(string c,int a) {
  ll num = 0;
  for(int i=0;i<c.size();i++) {
    num=((num*10)+(c[i]-'0'))%a;
  }
  return num;
}

ll GCD(ll a,ll b){
  if(b==0) {
    return a;
    return GCD(b,a%b);
  }
}

int main() {
  ll a,b;
  string c;
  cin>>a>>c;
  if(a==0) {
    cout<<c;
  }
  else {
    b=Fun(c,a);
    if(a>b) {
      swap(a,b);
    }
    ll result=1;
    result=GCD(a,b);
    cout<<result;
  }
}
