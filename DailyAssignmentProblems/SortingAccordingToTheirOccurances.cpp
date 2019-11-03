/*
(String)Input: 1 2 5 3 4 1 2 3 1 5 3 2 4 5 1 5 3 5

Output: 5 5 5 5 5 1 1 1 1 3 3 3 3 2 2 2 4 4
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main() {
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int ar[n],outputSeq[n],numberRepeat[n],count=0;
	bool status = false;
	
	for(int i=0;i<n;i++) { //need string
		cin>>ar[i];
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(ar[i] == ar[j]) {
				count++;
			}
		}
		
		//check the value that this added/counted before or not
		if(i > 1) {
    	for(int l=i-1;l>0;l--) {
    		if(ar[i] == ar[l]) {
    			status = true;
    		}
		}}
		
		if(!status) {
			outputSeq[i] = ar[i];
			numberRepeat[i] = count;
			count=0;
		}
	}
	
	
	cout<<endl<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<numberRepeat[i];j++) {
			cout<<outputSeq[i]<<endl;
		}
	}
}
