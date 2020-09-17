#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int MaxSumSubArray(int* arr, int n) {
  int curr_sum = 0;
  int global_max = INT_MIN;

//-1 4 -2 -5 6 -8
  for(int i=0;i<n;i++){
    curr_sum+=arr[i];
    if(curr_sum < 0){
      curr_sum = 0;
    }
    if(curr_sum > global_max) {
      global_max = curr_sum;
    }
  }
  return global_max;
}


int main(int argc, char const *argv[]) {
  int t,n;
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>n;
    int *ar = new int[n];
    cin>>ar[i];
    cout<<MaxSumSubArray(ar, n);
  }
  return 0;
}
