#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int MaxSumSubArray(int* arr, int n) {
  int curr_sum = 0;
  int global_max = INT_MIN;

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

int maximumSumRec(int **arr, int n, int m){
  int result = INT_MIN;
  for(int i=0;i<m;i++) {
    int *temp = new int[n]();
    for(int j=i;j<m;j++) {
      for(int k=0;k<n;k++) {
        temp[k] = temp[k]+arr[k][j];
      }
      int kadane_ans = MaxSumSubArray(temp, n);
      if(result < kadane_ans) {
        result = kadane_ans;
      }
    }
    delete temp;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  int t,n;
  int m;
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>n>>m;
    int **ar = new int*[n];
    for(int d=0;d<n;d++){
      ar[d] = new ll[m];
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>ar[i][j];
      }
    }
    cout<<maximumSumRec(ar, n, m);
  }
  return 0;
}
