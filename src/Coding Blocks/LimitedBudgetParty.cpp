#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define ll long long int

int main(int argc, char const *argv[]) {
    ll T;
    cin>>T;
    for(ll i=0;i<T;i++) {
        ll N,Cos;
        vector<ll> vect;
        cin>>N>>Cos;
        for(ll j=0;j<N;j++) {
            ll X;
            cin>>X;
            vect.push_back(X);
        }
        ll count=0,result=0;
        for(ll j=0;j<N;j++) {
            count=0;
            for(ll k=j;k<N;k++) {
                if((vect[k]+count)<Cos) {
                    count=count+vect[k];
                }
                if((vect[k]+count)==Cos) {
                    result++;
                    break;
                }
            }
            if(result) {
                break;
            }
        }
        if(result) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }

    }
}
