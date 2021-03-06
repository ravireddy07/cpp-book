#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;


#define SZ(x) ((int)(x.size()))
#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define FOD(i, a, n) for( i = int(a); i >= int(n); i--)
#define IN(x, y) ((y).find(x) != (y).end())
#define ALL(t) t.begin(),t.end()
#define MSET(tabl,i) memset(tabl, i, sizeof(tabl))
#define PSET(x,y) fixed<<setprecision(y)<<lf(x)
#define DBG(c) cout << #c << " = " << c << endl;
#define RTIME ((double)clock()/(double)CLOCKS_PER_SEC)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Mod 1000000007
#define ll long long int
typedef long double lf;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef complex<double> base;


template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;


ll x,y;
template<class T> T gcd(T a,T b) {
  if(a==0) {
    x=0,y=1;
    return b;
  }
  T gc=gcd(b%a,a);
  T temp;
  temp=x;
  x=y-(b/a)*temp;
  y=temp;
  return gc;
}


ll po(ll a, ll x,ll m) {
  if(x==0) {
    return 1;
  }
  ll ans=1;
  ll k=1;
  while(k<=x) {
    if(x&k) {
      ans=((ans*a)%m);
    }
    k<<=1;
    a*=a;
    a%=m;
  }
  return ans;
}

using namespace std;

int main() {
    ll t;
    cin>>t;
    for(int i=0;i<t;i++) {
        ll n;
        cin>>n;
        ll ans=0;
        ll i;
        FOI(i,0,n-1) {
            ll x;
            cin>>x;
            if(i!=0) {
              if(x%2!=0) {
                ans=ans xor i;
             }
            }
        }
        if(ans==0)
            cout<<"Second"<<endl;
        else
            cout<<"First"<<endl;
    }
}
