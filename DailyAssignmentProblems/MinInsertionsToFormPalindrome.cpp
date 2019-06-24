#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int

int FindMin(int one, int two) {
    int k = one<two? one:two;
	return k;
}

ll Palindrome(char str[], int n, int nn) {
	if(n>nn) {
        return INT_MAX;
    }
    if(n==nn) {
        return 0;
    }
    if(n==nn-1) {
        return (str[n] == str[nn])? 0 : 1;
    }

    ll result_1 = Palindrome(str, n+1, nn-1);
    ll result_2 = FindMin(Palindrome(str, n, nn-1), Palindrome(str, n+1,nn))+1;

	return (str[n] == str[nn])? result_1 : result_2;
}

int main() {
	char str[1000];
	cin>>str;
	cout<<Palindrome(str, 0, strlen(str)-1);
	return 0;
}
