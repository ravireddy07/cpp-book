#include <iostream>
using namespace std;

int main() {
  ll t,p=1000000000,c=0,n;
  cin>>t;
  for(int i=0;i<t;i++) {
    cin>>n;
    if(n>p) {
      p=n;
      break;
    }
    p=n;
  }
  while(t--) {
    cin>>n;
    if(n<p) {
      cout<<"false";
      return 0;
    }
    p=n;
  }
  cout<<"true";
  return 0;
}
