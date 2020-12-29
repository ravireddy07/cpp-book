#include <iostream>
using namespace std;

int StrMatch(string& s1, int n, int k, char ch)
{
	int lenn = 1;
	int count = 0;
	int l=0,r=0;
	while(r<n) {
		if (s1[r] != ch){
			count++;
		}
		while (count>k) {
			if (s1[l] != ch){
				count--;
			}
			l++;
		}
		lenn = max(lenn, r - l + 1);
		r++;
	}
	return lenn;
}

int SanketString(string& s1, int n, int k)
{
	int lenn = 1;
	for (int i=0;i<26;i++){
		lenn = max(lenn, StrMatch(s1, n, k, i+'A'));
		lenn = max(lenn, StrMatch(s1, n, k, i+'a'));
	}
	return lenn;
}

int main(int argc, char const *argv[]){
	int k;
	string s1;
	cin>>k;
	cin>>s1;
	cout <<SanketString(s1, s1.size(), k);
	return 0;
}
