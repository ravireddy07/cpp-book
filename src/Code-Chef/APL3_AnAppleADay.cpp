#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin>>t;
	while(t--) {
	    cin>>n;
	    vector<int> ar(n);
	    fill(ar.begin(), ar.end(), 0);
	    int count, sum=0;
	    for(int i=0;i<n;i++) {
	        cin>>ar[i];
	        sum += ar[i];
	    }
	    float a = (float)sum/n;
	    count = ceil(a);
	    cout<<count<<endl;
	}
	return 0;
}
