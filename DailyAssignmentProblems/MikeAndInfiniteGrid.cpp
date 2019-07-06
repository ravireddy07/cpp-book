#include<iostream>
#include<bits/stdc++.h>
using namespace std;
​
int f1[1100][1100],f2[1100][1100],f3[1100][1100],win[1100][1100];

int main() {
    f1[0][0]=1;
    f2[0][0]=1;
    f3[0][0]=1;
    for(int i=1;i<1100;i++) {
        for(int j=1;j<1100;j++) {
            if(f1[i][j-1]) {
                f1[i][j]=1;
            }
            if(f2[i-1][j]) {
                f2[i][j]=1;
            }
            if(f3[i-1][j-1]) {
                f3[i][j]=1;
            }
            if(!f1[i][j-1] && !f2[i-1][j] && !f3[i-1][j-1]) {
                f1[i][j]=1;
                f2[i][j]=1;
                f3[i][j]=1;
                win[i][j]=1;
            }
        }
    }
    int t;
    cin>>t;
    int n,m,p,q;
    for(int h=0;h<t;h++) {
        cin>>n>>m>>p>>q;
        if(win[n-p][m-q]) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
