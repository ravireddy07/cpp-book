#include<iostream>
using namespace std;

#define ll long long int

bool IsItSafe(ll ar[100], ll n,ll m,ll ans) {
  int student=1;
  ll currentpages=0;
  for(ll i=0;i<n;i++) {
    if(ar[i]>ans) {
      return false;
    }
    if(currentpages+ar[i]>ans) {
      currentpages=ar[i];
      student++;
      if(student>m) {
        return false;
      }
    }
    else {
      currentpages=currentpages+ar[i];
    }
  }
  return true;
}

ll MaxP(ll ar[100],ll n,ll m) {
  int start=0;
  ll sum=0;
  ll end;
  for(int i=0;i<n;i++) {
    sum=sum+ar[i];
  }
  end=sum;
  ll result=0;
  while(start<=end) {
    ll mid=(start+end)/2;
    if(IsItSafe(ar,n,m,mid)) {
      end=mid-1;
     result=mid;
    }
    else {
      start=mid+1;
    }
  }
  return result;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	ll n,m;
	ll ar[100];
	int k=1;
	while(k<=t)	{
    cin>>n>>m;
    for(int i=0;i<n;i++) {
      cin>>ar[i];
    }
    ll y = MaxP(ar,n,m);
    cout<<y<<endl;
    k++;
	}
	return 0;
}
