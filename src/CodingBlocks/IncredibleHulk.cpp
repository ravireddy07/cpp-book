#include<iostream>
using namespace std;

#define ll long long int
#define ul unsigned long long int

ll convertDecimalToBinary(ul);

int main () {
  ul n;
  cin>>t;
  ul arr[n], i;
  for(i=1;i<=n;i++)
      cin >> arr[i-1];

  for(i=0;i<n;i++) {
    ul binaryNumber, sum=0;
    binaryNumber = Hulk(arr[i]);
    while (binaryNumber != 0) {
      ul t;
      t=binaryNumber%2;
      sum = sum+t;
      binaryNumber = binaryNumber/10;
    }
    cout<<sum<<endl;
  }
  return 0;
}


ll Hulk(ul n) {
  ll binaryNumber = 0;
  ul remainder, i = 1, step = 1;

  while(n!=0) {
    remainder = n%2;
    n /= 2;
    binaryNumber += remainder*i;
    i *= 10;
  }
  return binaryNumber;
}
