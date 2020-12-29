// Time complexity will be O(MAX*log(MAX))
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,q,i,j,ele;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
        
    ll MAX=*max_element(a,a+n);
    ll cnt[MAX+1]={0};
    ll ans[100005]={0};

    for(i=0;i<n;i++)
        cnt[a[i]]++;

    for(i=1;i<=MAX;i++) {
        ans[i]=cnt[i];
        for(j=2*i;j<=MAX;j+=i)
             ans[i]+=cnt[j];
    }

    cin>>q;
    while(q--) {
        cin>>ele;
        cout<<ans[ele]<<endl;
    }
}
