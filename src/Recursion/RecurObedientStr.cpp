#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool Obideint(char s[],int be,int en) {
  if(be>en) {
    return true;
  }
  if(s[0]!='a') {
    return false;
  }
  if(s[be]=='a') {
    if(s[be+1]=='b' && s[be+2]=='b') {
      bool istrue=Obideint(s,be+1,en);
      if(istrue) {
        return true;
      }
      else {
        return false;
      }
    }
    else if(s[be+1]=='a' || s[be+1]=='\0') {
      bool istrue=Obideint(s,be+1,en);
      if(istrue) {
        return true;
      }
      else {
        return false;
      }
    }
  }
  if(s[be]=='b' && s[be+1]=='b') {
    if(s[be+2]=='a' || s[be+2]=='\0') {
      bool istrue=Obideint(s,be+2,en);
      if(istrue) {
        return true;
      }
      else {
        return false;
      }
    }
  }
  return false;
}

int main() {
    char s[100000];
    cin>>s;
    cout<<boolalpha<<Obideint(s,0,strlen(s)-1);
    return 0;
}
