#include <iostream>
using namespace std;

int DP[100000] = {0};

int f(int n) {
	// Base case
	if(n==0 or n==1) return n;
	if(DP[n] != 0) return DP[n];

	DP[n] = f(n-1) + f(n-2);
	return f(n-1) + f(n-2);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<f(n);
	return 0;
}
