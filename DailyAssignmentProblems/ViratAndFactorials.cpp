#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define max 100

int Fun(int no[],int no_size,int x) {
  int multi;
  int carr = 0;
  for(int i=0;i<no_size;i++) {
    multi = (no[i]*x)+carr;
    no[i] = product%10;
    carr = multi/10;
  }
  while(carr) {
    no[no_size]=carr%10;
    carr = carr/10;
    no_size++;
  }
  return no_size;
}


void Fact(int n) {
  int no[max], no_size=1, x;
  no[0]=1;
  for(x=2;x<=n;x++) {
    no_size=mult(no,no_size,x);
  }
  for(int i=no_size-1;i>=0;i--) {
    cout<<no[i];
  }
}


int main() {
  int n;
  cin>>n;
  Fact(n);
  return 0;
}
