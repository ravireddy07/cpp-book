#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[100][100];

ll sum(ll *arr, ll i, ll j){
  ll result = 0;
  for(ll k=i;k<=j;k++) {
    result = ((result %100) + (arr[k]%100))%100;
  }
  return result;
}

ll mixtures(ll *arr, ll i, ll j) {
  if(i==j) return 0;
  if(abs((int)(i-j)) == 1) return arr[i]*arr[j];
  if(dp[i][j] != -1) return dp[i][j];
  ll result = INT_MAX;
  for(ll k=i+1;k<=j;k++){
    ll retval = mixtures(arr, i, k-1) + mixtures(arr, k, j) + (sum(arr, i, k-1)*sum(arr, k, j));
    if(retval < result) result = retval;
  }
  dp[i][j] = result;
  return result;
}


int main(int argc, char const *argv[]) {
  ll n;
  cin>>n;
  ll *arr = new ll[n];
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }

  for(ll i=0;i<100;i++){
    for(ll j=0;j<100;j++){
      dp[i][j] = -1;
    }
  }
  cout<<mixtures(arr, 0, n);
  return 0;
}
