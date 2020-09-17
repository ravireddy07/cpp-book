#include<iostream>
using namespace std;
#define ll long long int

ll a[100000000];

int HelpRahul(ll a[],ll s,ll e,ll key) {
  if(s>e) {
    return -1;
  }
  ll mid=(s+e)/2;
  if(key==a[mid]) {
    return mid;
  }
  if(a[s]>=a[mid])  {
    if(key>=a[mid]  && key<=a[e]) {
      return HelpRahul(a,mid+1,e,key);
    }
    else {
      return HelpRahul(a,s,mid-1,key);
    }
  }
  if(a[s]<key && key<=a[mid]) {
    return HelpRahul(a,s,mid-1,key);
  }
  return HelpRahul(a,mid+1,e,key);
}


int main() {
   ll n;
   cin>>n;
   for(int i=0;i<n;i++) {
     cin>>a[i];
    }
  ll key;
  cin>>key;
  cout<<HelpRahul(a,0,n-1,key)<<endl;
	return 0;
}
