#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define sizz 100000001
#define ll long long int

bool sieve[sizz];
int main() {
  int N;
  cin>>N;
  sieve[0]=sieve[1]=1;
  for(int i=2;i*i<=sizz-1;i++)
  if(!sieve[i])
      for(int j=i*i;j<=sizz-1;j+=i)
          sieve[j]=1;

  ll result=1;
  while(N && result<sizz-1) {
    result++;
    if(!sieve[result])
        N--;
  }
  cout<<result;
}
