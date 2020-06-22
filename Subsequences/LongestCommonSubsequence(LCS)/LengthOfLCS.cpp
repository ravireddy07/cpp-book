#include <iostream>
using namespace std;

int dp[1000][1000];

int lcs(string s1, string s2) {
	if(s1.size() == 0 or s2.size()==0) {
		return 0;
	}
	if(s1[0] == s2[0]) {
		return 1+lcs(s1.substr(1), s2.substr(1));
	} else {
		return max(lcs(s1, s2.substr(1)), lcs(s1.substr(1), s2));
	}
}

int lcsTD(string s1, string s2) {
	if(s1.size() == 0 or s2.size()==0) {
		return 0;
	}

	if(dp[s1.size()][s2.size()]!=-1) {
		return dp[s1.size()][s2.size()];
	}
	long long int ans;
	if(s1[0] == s2[0]) {
		ans = 1+lcsTD(s1.substr(1), s2.substr(1));
	} else {
		ans = max(lcsTD(s1, s2.substr(1)), lcsTD(s1.substr(1), s2));
	}
	dp[s1.size()][s2.size()] = ans;
	return ans;
}

int main(int argc, char const *argv[])
{
	string s1, s2;
	cin>>s1>>s2;
	for(int i=0;i<1000;i++) {
		for(int j=1;j<1000;j++) {
			dp[i][j]=-1;
		}
	}
	cout<<lcsTD(s1, s2)<<endl;

	return 0;
}
