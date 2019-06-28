#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define fio ios_base::sync_with_stdio(false)

#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)

#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define all(v) v.begin(), v.end()
ll lent = 1e18;
vector<ll>primes;
ll dp[20][65536];

ll gcd(ll a , ll b) {
    return b==0?a:gcd(b,a%b);
}

void Sieve_set() {
  primes.push_back(1);
  primes.push_back(2);
  vector<bool>pr(50,true);
  for(ll i=3;i*i<=50;i+=2){
    if(pr[i]){
      for(ll j=i*i;j<=50;j+=2*i)pr[j]=false;
    }
  }
  for(ll i=3;i<=50;i+=2)if(pr[i])primes.push_back(i);
}

ll FriendCB(ll FVar1,ll last,ll temp1, ll P) {
  if(__builtin_popcount(temp1) == FVar1+1)
      return 0ll;
  if(dp[last+1][temp1] != -1)
      return dp[last+1][temp1];
  ll temp2=lent;
  for(ll i=0;i<=FVar1;i++) {
    if((1<<i)&temp1) {
        continue;
    }
    if(last==-1) {
        temp2=min(temp2,FriendCB(FVar1,i,temp1|(1<<i),P));
    }
    else {
        temp2=min(temp2,((primes[last]*primes[i])%P+FriendCB(FVar1,i,temp1|(1<<i),P)));
    }
  }
  return dp[last+1][temp1]=temp2;
}

int main() {
  ll t;
  //cin>>t;
  s(t);
  Sieve_set();
  for(int i=0;i<t;i++) {
    memset(dp,-1,sizeof(dp));
    ll N,P;
    //cin>>N>>P;
    s2(N,P);
    ll var1 = lower_bound(all(primes),N) - primes.begin();
    if(var1 == primes.size() || primes[var1]!=N)
        var1--;
    // cout<<var1<<endl;
    ll result = FriendCB(var1,-1,0ll,P);
    p(result);
  }
  return 0;
 }
