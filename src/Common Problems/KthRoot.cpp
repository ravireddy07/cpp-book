#include <iostream>
#include<math.h>
using namespace std;

#define ll long long int

int main() {
    ll i,j,s,e,mid;
    int t;
    cin>>t;
    while(t--) {
        cin>>i>>j;
        s=0;e=i;
        int k=j,p=0;
        while(k!=1) {
          k=k/2;
          p++;
        }
        while(p>0) {
          e=sqrt(e);
          p--;
        }
        while(s<e) {
          mid=(s+e)/2;
          ll a=pow(mid,j);
          if(a>i) {
            e=mid-1;
          }
          else if(a<i) {
            s=mid+1;
          }
          else if(a==i) {
            break;
          }
        }
        cout<<mid+1<<endl;
    }
  }
