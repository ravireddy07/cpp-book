#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int kadane(ll* arr, ll* start, ll* end, ll n) {
	ll sum = 0, result = INT_MIN, local_start = 0;
	*end = -1;

	for(ll i=0;i<n;++i) {
		sum += arr[i];
		if(sum<0) {
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > result) {
			result = sum;
			*start = local_start;
			*end = i;
		}
	}
	if (*end != -1)
		return result;

	result = arr[0];
	*start = *end = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > result)
		{
			result = arr[i];
			*start = *end = i;
		}
	}
	return result;
}

void MaxSumRect2D(ll **ar, ll n, ll m) {
	ll result = INT_MIN;
	ll temp[n], sum, start, end;

	for(int i=0;i<m;++i) {
		memset(temp, 0, sizeof(temp));
		for(int j=i;j<m;++j) {
			for (int k=0;k<n;++k){
				temp[k] += ar[k][j];
			}
			sum = kadane(temp, &start, &end, n);
			if(sum>result) {
				result = sum;
			}
		}
    }
    cout<<result<<endl;
	return;
}

int main(int argc, char const *argv[]) {
	ll t,n,m;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		ll **arr = new ll*[n];
		for(int d=0;d<n;d++) {
			arr[d] = new ll[m];
		}
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				cin>>arr[j][k];
			}
		}
	  MaxSumRect2D(arr, n, m);
	}
	return 0;
}
