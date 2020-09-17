#include<iostream>
using namespace std;

int findPivot(int a[],int s,int e) {
  if(s>e) {
    return -1;
  }
  while(s<=e) {
    int mid = (s+e)/2;
    if(mid<e&&a[mid]>a[mid+1]) {
      return mid;
    }
    if(mid>s&&a[mid]<a[mid-1]) {
      return mid-1;
    }
    if(a[s]>=a[mid]) {
      e = mid-1;
    }
    else {
      s = mid + 1;
    }
  }
  return -1;
}


int main() {
  int n;
  cin>>n;
  int b[n];
  for(int i=0;i<n;i++){
    cin>>b[i];
  }
  cout<<findPivot(b, 0, n)<<endl;
    return 0;
}
