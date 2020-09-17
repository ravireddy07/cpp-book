#include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

int LCS(string str1, string str2, string str3, int one,int two, int three) {
	int arr[one+1][two+1][three+1];

	for(int i=0;i<=one;i++) {
		for(int j=0;j<=two;j++) {
			for(int k=0;k<=three;k++) {
				if(i == 0 || j == 0||k == 0)
					 arr[i][j][k] = 0;
				else if(str1[i-1] == str2[j-1] && str1[i-1]==str3[k-1])
					arr[i][j][k] = arr[i-1][j-1][k-1] + 1;
				else
					arr[i][j][k] = max(max(arr[i-1][j][k], arr[i][j-1][k]), arr[i][j][k-1]);
			}
		}
	}
	return arr[one][two][three];
}


int main() {
  int t;
  cin>>t;
  for(int i=0;i<t;i++) {
    string str1,str2,str3;
    cin>>str1>>str2>>str3;

    cout<<LCS(str1, str2, str3, str1.length(), str2.length(), str3.length())<<endl;
  }
	return 0;
}
