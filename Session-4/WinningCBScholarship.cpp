#include <iostream>
#define ll long long int
using namespace std;

bool check(ll n, ll m, ll x, ll y, ll result) {
	return ((n-result)*y + m) >= result*x;
}

int main(int argc, char const *argv[])
{
	ll n,m,x,y;
	cin>>n>>m>>x>>y;
	ll start = 1, end = n;
	ll result = -1;
	while(start <= end) {
		ll mid = (start+end)/2;
		if(check(n,m,x,y, mid)) {
			start = mid+1;
			result = mid;
		} else {
			end = mid-1;
		}
	}
	cout<<result;
	return 0;
}
