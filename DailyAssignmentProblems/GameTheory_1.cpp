#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define ll long long int
ll table[1000004];

unordered_set Num_Divisors(long long n) {
    unordered_set tt;
    for(ll i=2;i*i<=n;i++) {
        if(n%i==0) {
            if(n/i!=i) {
                tt.insert(n/i);
                tt.insert(i);
            }
        }
        tt.insert(1);
        return tt;
    }

    ll FindMax(unordered_set Set) {
        ll Mex = 0;
        while(Set.find(Mex) != Set.end()) {
            Mex++;
        }
        return (Mex);
    }

    int Grundy(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 0;
        if(table[n]!=0)
            return table[n];
        unordered_set s=Num_Divisors(n);
        unordered_set ss;
        for(auto i=s.begin();i!=s.end();i++) {
            ll x=*i;
            ss.insert(Grundy(x));
        }
        ll xx=FindMax(ss);
        table[n]=xx;
        return xx;
    }
}

int main() {
    int t;
    cin>>t;
    for(int ii=0;ii<t;ii++) {
        memset(table,0,sizeof(table));
        int n,m;
        cin>>n>>m;
        ll ans=Grundy(m);
        if(n%2==0) {
            cout<<"2"<<endl;
        }
        else {
            if(ans==0)
                cout<<"2"<<endl;
            else
                cout<<"1"<<endl;
        }
    }
    return 0;
}
