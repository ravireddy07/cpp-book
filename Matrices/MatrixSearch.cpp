#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void MatSearch(int **ar, int n , int m, int val) {
  for(int row=0;row<n;) {
    for(int col=m-1;col>=0 and row < n;) {
      if(ar[row][col] == val) {
        cout<<1;
        return;
      }
      else if(ar[row][col]>val) {
        col--;
      }
      else {
        row++;
      }
    }
  }
  cout<<0;
  return ;
}

int main() {
  int n, m;
  cin>>n>>m;
  int **ar = new int*[n];
  for(int i=0;i<n;i++) {
    ar[i]=new int[m];
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin>>ar[i][j];
    }
  }
  int val;
  cin>>val;
  MatSearch(ar, n, m, val);
}
