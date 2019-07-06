#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

int main() {
  string s1, s2;
  int t;
  cin>>t;
  for(int i=0;i<t;i++) {
      cin>>s1>>s2;
      for(size_t i=0;i<s1.length();i++) {
          if(s1[i] == s2[i]) {
              s1[i] = '0';
          }
          else {
              s1[i] = '1';
          }
    }
    cout<<s1<<endl;
  }
    return 0;
}
