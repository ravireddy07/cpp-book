#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) {
    cin>>arr[i];
  }

  int harry=0;

  for(int i=0;i<n;i++) {
    harry^=arr[i];
  }

  int result = harry;
  int count = 0;

  if(!(harry&1)) {
    count++;
    harry >>= 1;
  }
  harry = 1;
  while(count--) {
    harry <<= 1;
  }
  int temp1 = 0;
  int temp2 = 0;

  for(int i=0;i<n;i++) {
    if((arr[i]&harry) != 0) {
      temp1^=arr[i];
    }
  }
  temp2 = result^temp1;

  if(temp1<temp2) {
    cout<<temp1<<" "<<temp2<<endl;
  }
  else {
    cout<<temp2<<" "<<temp1<<endl;
  }
  return 0;
}
