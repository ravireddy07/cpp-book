#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
  int t;
  cin>>t;
  int result = 0;
  for(int i=0;i<t;i++) {
    int n;
    cin>>n;
    result^=n;
  }
  cout<<result<<endl;
  return 0;
}
