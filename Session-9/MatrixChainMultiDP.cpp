#include<bits/stdc++.h>
using namespace std;

int dp[105][105];

int MCM(int *arr, int i, int j) {
  if(abs((int)(i-j)) == 1){
    return 0;
  }
  if(dp[i][j] != -1) return dp[i][j];
  int result = INT_MAX;
  for(int k=i;k<=j-2;k++) {
    int retval = MCM(arr, i, k+1) + MCM(arr, k+1, j) +arr[i-1]*arr[k]*arr[j-1];
    if(retval < result) {
      result = retval;
    }
  }
  dp[i][j] = result;
  return result;
}
/*
Input:
2 Test_Cases
5
1 2 3 4 5
3
3 3 3
*/
int main(int argc, char const *argv[]) {
  int n,t;
  cin>>t;

  for(int i=0;i<t;i++){
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++) {
            dp[i][j] = -1;
        }
    }
    cout<<MCM(arr, 1, n)<<endl;
 }

  return 0;
}
