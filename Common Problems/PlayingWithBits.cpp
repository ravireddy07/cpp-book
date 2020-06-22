#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll playwithbits(ll a) {
    int ans = 0;
    for(;a>0; a= a>>1)
        ans += a&1;
    return ans;
}

int main() {
    ll q,a,b,ans;
    cin>>q;
    while(q!=0) {
        cin>>a>>b;
        ans = 0;
        for(ll i = a; i<=b; i++)
         ans += playwithbits(i);
        cout<<ans<<endl;
        q--;
    }
}
