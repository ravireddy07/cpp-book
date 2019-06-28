#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int Unique3(int arr[], int n) {
  int siz[64] = {0};
  for(int i=0;i<n;i++) {
    int j=0;
    int num = arr[i];
    while(num>0) {
      siz[j]+= num&1;
      j++;
      num>>=1;
    }
  }
  int temp=1;
  long result=0;
  for(int i=0;i<64;i++) {
    siz[i] %= 3;
    result += siz[i]*temp;
    temp = temp<<1;
  }
  return result;
}


int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) {
    cin>>arr[i];
  }
  cout<<Unique3(arr, n);
  return 0;
}
