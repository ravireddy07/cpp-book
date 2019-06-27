#include <iostream>
#include<climits>
using namespace std;
int dp[5000][5000]={};
bool sub(int a[],int n,int key){
    bool dp[5000][5000]={0};
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    dp[0][a[0]]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<=key;j++)
            if(j<a[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i]];
    return dp[n-1][key];
}

int main() {
    int n,k,a[5000];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(sub(a,n,k)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
