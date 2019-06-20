#include <iostream>
using namespace std;

long long int result = 0;

void ones(long long int n, string osf) {
	// Base case
	if(n==0) {
		result++;
		return;
	}
	// Recursion
	ones(n-1, osf+"0");
	if(osf.size()==0 or osf[osf.size()-1]=='0') {
		ones(n-1, osf+"1");
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	long long int n;
	long long int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    result=0;
	    cin>>n;
	    ones(n,"");
	    cout<<result<<endl;
	}
	return 0;
}
