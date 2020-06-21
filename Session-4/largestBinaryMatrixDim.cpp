#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int DParr[100000] = {0};

void check(int i, int j, int arr, int n){
    if(arr[i+1][j] == 1 and arr[i][j+1] == 1 and arr[i+1][j+1] == 1){
        result++;
    }
}

void BinaryMatrix(int arr, int n) {
    //
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1){
                check(i, j, arr, n);
            }
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
    int ar[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ar[i][j];
        }
    }
	cout<<BinaryMatrix(ar, n);
	return 0;
}
