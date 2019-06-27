#include<bits/stdc++.h>
#include<cstring>

using namespace std;
void LCS(string inp,string out) {
	int dp[1000][1000]={};
	int m=inp.length();
	int n=out.length();
	dp[0][0]=0;
  for(int i=0;i<=m;i++)
     dp[i][0]=0;

  for(int i=0;i<=n;i++)
     dp[0][i]=0;

     for(int i=1;i<=m;i++) {
       for(int j=1;j<=n;j++) {
         if(inp[i-1]==out[j-1])
            dp[i][j]=1+dp[i-1][j-1];
         else
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
      }
    }

    int i=m,j=n;
    int index=dp[m][n];
    char common[index+1];
    common[index]='\0';
    int temp = index;
    while(i>0 && j>0) {
      if(inp[i-1]==out[j-1]) {
        common[index-1]=inp[i-1];
        i--;
        j--;
        index--;
      }
      else if(dp[i-1][j]>dp[i][j-1]) {
        i--;
      }
      else
        j--;
     }
     for(int k=0; k<temp; k++) {
       cout<<common[k];
    }
    cout<<endl;
}
int main() {
	string inp,out;
	cin>>inp;
	cin>>out;
	LCS(inp,out);
	return 0;
}
