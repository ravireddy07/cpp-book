#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[1005][1005];

ll SanjeetString(string str) {
    memset(dp, 0, sizeof(dp));
    for(ll i=0;i<str.size();i++) {
        dp[i][i] = 1;
    }
    for(ll l=2;l<=str.size();l++) {
        for(ll i=0;i<str.size();i++) {
            ll j=i+l-1;
            if(str[i] == str[j]) {
                dp[i][j] = dp[i+1][j-1]+2-(i==j);
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return str.size()-dp[0][str.size()-1];
}

int main(int argc, char const *argv[]) {
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++) {
      string str;
      cin>>str;
      cout<<SanjeetString(str)<<endl;
    }
    return 0;
}
