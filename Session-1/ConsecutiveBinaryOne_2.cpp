#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int ones(int n){
    int ar1[n],ar2[n];
    ar1[0] = 1;
    ar2[0] = 1;

    for(int i=1;i<n;i++){
        ar1[i] = ar1[i-1] + ar2[i-1];
        ar2[i] = ar1[i-1];
    }
    return (ar1[n-1]+ar2[n-1]);
}

int main(int argc, char const *argv[]){

    int n,t;
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>n;
        cout<<ones(n)<<endl;
    }
    return 0;
}
