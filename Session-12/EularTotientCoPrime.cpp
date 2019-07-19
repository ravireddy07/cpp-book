#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int* FindCoPrime(int n) {
  int *arr = new int[n+1];
  for(int i=0;i<=n;i++) {
    arr[i] = i;
  }

  for(int i=2;i<=n;i++) {
    if(arr[i] == i) {
      for(int j=i*2;j<=n;j+=i) {
        arr[j] = (arr[j] * (i-1))/(i);
      }
      arr[i]--;
    }
  }
  return arr;
}


int main(int argc, char const *argv[]) {
  int *arr;
  arr = FindCoPrime(100);
  for(int i=0;i<100;i++) {
    cout<<ar[i]<<" ";
  }

  return 0;
}
