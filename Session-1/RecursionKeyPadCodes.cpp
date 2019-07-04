#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int result =0;

string Keypad[10]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void printKeypadString(string ini,char out[],int i,int j,int n) {
  if(i==n) {
    out[j]='\0';
    cout<<out<<" ";
    return;
  }
  int no=int(ini[i])-48;

  for(int k=0;Keypad[no][k]!='\0';k++) {
    out[j]=Keypad[no][k];
    printKeypadString(ini,out,i+1,j+1,n);
  }
}


int main() {
    string str;
    char out[10000];
    cin>>str;
    printKeypadString(str,out,0,0,str.size());
    cout<<endl<<result;
}
