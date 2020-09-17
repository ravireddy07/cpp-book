#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 100
int L[N][N];

set<string> findLCS(string X, string Y, int m, int n) {
	set<string> s;
	if (m == 0 || n == 0) {
		s.insert("");
		return s;
	}

	if (X[m - 1] == Y[n - 1]){
		set<string> tmp = findLCS(X, Y, m - 1, n - 1);
		for (string str : tmp)
			s.insert(str + X[m - 1]);
	}

	else{
		if (L[m - 1][n] >= L[m][n - 1])
			s = findLCS(X, Y, m - 1, n);
		if (L[m][n - 1] >= L[m - 1][n])	{
			set<string> tmp = findLCS(X, Y, m, n - 1);
			s.insert(tmp.begin(), tmp.end());
		}
	}
	return s;
}

void LCS(string X, string Y, int m, int n) {
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
    return ;
}

int main()
{
	string X,Y;
	cin>>X>>Y;
	long long int m = X.length();
	long long int n = Y.length();

	LCS(X, Y, m, n);
	set<string> s = findLCS(X, Y, m, n);
	for (string str : s)
		cout<<str<<endl;
	return 0;
}
