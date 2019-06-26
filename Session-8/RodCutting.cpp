#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll rodCut(ll n, ll ar[]) {
    ll result[n+1];
    result[0]=0;
    for(ll i=1;i<=n;i++) {
        result[i]=INT_MIN;
        for(ll j=0;j<i;j++) {
            result[i]=max(result[i],ar[j]+result[i-(j+1)]);
        }
    }
    return result[n];
}

int main(int argc, char const *argv[]) {
    ll n;
    cin>>n;
    ll ar[n];
    for(ll i=0;i<n;i++){
        cin>>ar[i];
    }
    cout<<rodCut(n, ar)<<endl;
    return 0;
}
