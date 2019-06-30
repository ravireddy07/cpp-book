#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        int N,Cos;
        vector<int> vect;
        cin>>N>>Cos;
        for(int j=0;j<N;j++) {
            int X;
            cin>>X;
            vec.push_back(X);
        }
        int count=0,result=0;
        for(int j=0;j<N;j++) {
            count=0;
            for(int k=j;k<N;k++) {
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
