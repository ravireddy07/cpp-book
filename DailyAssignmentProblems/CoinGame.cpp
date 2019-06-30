#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void coinPick(int ar, int n,int input) {
    int ar1[n/2],ar2[n/2];
    int count;
    if(input == 1){
        for(int i=n;i>=0;i--) {
            ar1[count] = ar[i];
            ar2[count] = ar[i-1];
            i--;
        }
    }
    else{
        for(int i=n;i>=0;i*2) {
            ar2[count] = ar[i];
            ar1[count] = ar[i-1];
            }
    }
    max(ar1, ar2, n);
    return;
}

int max(int ar1, ar2, n) {
    int Asum = 0, Bsum = 0;
    for(int i=0;i<n;i++) {
        Asum = Asum + ar1[i];
        Bsum = Bsum + ar2[i];
    }
    if(Asum > Bsum) {
        cout<<"A"<<endl;
    }
    else {
        cout<<"B"<<endl;
    }
    return;
}

int main() {
    int n, input;
   int ar[n];
   for(int i =0;i<n;i++){
       cin>>ar[i];
   }

    int size = sizeof(ar)/sizeof(ar[0]);
    sort(ar, ar+size);

   cin>>input;
   coinPick(ar, n, input);
   return 0;
}
