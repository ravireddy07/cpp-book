#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int

int a[1000001]={0};

int GCD(int one,int two) {
    if(one%two == 0) {
      return two;
    }
    return GCD(two,one%y=two);
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    if(a[n] != 0) {
      cout<<a[n]<<endl;
    }
    else {
      int result=1;
      for(int i=2;i<n;i++) {
        if(GCD(n,i) == 1) {
          result++;
        }
      }
      cout<<result<<endl;
      a[n]=result;
    }
  }
}
