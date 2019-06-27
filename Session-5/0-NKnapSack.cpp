#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long int

vector<ll>size_list;
vector<ll>value_list;

ll N_KnapSack(ll s) {
  ll n = value_list.size();
  vector<ll>dp;
  dp.reserve(s+1);
  dp[0]=0;

  for(ll i=1;i<=s;++i) {
    dp[i]=0;
    for(ll j=0;j<=n;++j) {
      if(size_list[j] <= i) {
        dp[i] = max(dp[i], (dp[i-size_list[j]]+value_list[j]));
      }
    }
  }
  return dp[s];
}

int main () {
  ll n,s;
  cin>>n>>s;
  size_list.reserve(n);
  value_list.reserve(n);

  for(ll i=0;i<n;i++) {
    ll d;
    cin>>d;
    size_list.push_back(d);
  }
  for(ll i=0;i<n;i++) {
    ll d;
    cin>>d;
    value_list.push_back(d);
  }
  cout<<N_KnapSack(s)<<endl;
  return 0;
}
