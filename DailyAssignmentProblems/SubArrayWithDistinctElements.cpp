#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sumOflength(int *arr, int n) {
    unordered_set<int> s;
    int j=0, ans=0;
    for(int i=0;i<n;i++) {
        while(j<n and s.find(arr[j])==s.end()) {
            s.insert(arr[j]);
            j++;
        }
        ans+= ((j-i)*(j-i+1))/2;
        s.erase(arr[i]);
    }
    return ans;
}


int main() {
	int n;
	cin>>n;
	int *arr = new int[n];

	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<sumOflength(arr, n)<<endl;
	return 0;
}
