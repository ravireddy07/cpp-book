#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int MBS(int *ar, ll n) {
  int *lis = new int[n];
  int *lbs = new int[n];
  int *lds = new int[n];

  for(int i=0;i<n;i++) {
    lis[i] = 1;
    lds[i] = 1;
  }

  for(int i=1;i<n;i++) {
    for(int j=0;j<i;j++) {
      if(ar[i]>ar[j]) {
        lis[i] = max(lis[i], 1+lis[j]);
      }
    }
  }

  for(int i=n-2;i>=0;i--) {
    for(intj=n-1;j>i;j--) {
      if(ar[i] > ar[j]) {
        lds[i] = max(lds[i], lds[j]+1);
      }
    }
  }

  for(int i=0;i<n;i++) {
    lbs[i] = lis[i]+lds[i]-1;
  }
  int result = -1;
  for(int i=0;i<n;i++) {
    if(lbs[i] > result) result = lbs[i];
  }
  return result;
}

int main(int argc, char const *argv[]) {
  ll n;
  cin>>n;
  int *arr = new int[n];
  for(int i=0;i<n;i++) {
    cin>>ar[i];
  }

  MBS(ar, n);
  return 0;
}
