#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int dp0[100100],dp1[100100];

int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  for(int ii=0;ii<t;ii++) {
    string s;
    cin>>s;
    int st=1,sr=1,n=s.length();
    dp0[0]=1,dp1[n-1]=1;
    for(int i=1;i<n;i++) {
      if(s[i]==s[i-1]) {
        dp0[i]=dp0[i-1]^st^(st+1);
        st++;
      }
      else {
        dp0[i]=dp0[i-1]^1;
        st=1;
      }
      if(s[n-i]==s[n-i-1]) {
        dp1[n-i-1]=dp1[n-i]^sr^(sr+1);
        sr++;
      }
      else {
        dp1[n-i-1]=dp1[n-i]^1;
        sr=1;
      }
    }
    if(!dp0[n-1]) {
      cout<<"Yes"<<endl;
      continue;
    }

    int flag=0;
    for(int i=0;i<n-1;i++) {
      if(dp0[i]^dp1[i+1])
          continue;
      flag=1;
      break;
    }
    if(flag)
       cout<<"Yes"<<endl;
    else
       cout<<"No"<<endl;
  }
  return 0;
}
