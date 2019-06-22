#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool is_anagram(string s1,string s2) {
  int str1[26]={0};
  int str2[26]={0};
  bool flag=true;
  for(int i=0;i<s1.length();i++) {
    str1[s1[i]-'a']++;
  }
  for(int i=0;i<s2.length();i++) {
    str2[s2[i]-'a']++;
  }
  for(int i=0;i<26;i++) {
    if(str1[i]!=str2[i]) {
      flag=false;
      break;
    }
  }
  return flag;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
    int n;
    cin>>n;
    vector<string>vect(n);
    unordered_map<string,bool>mp;
    for(int i=0;i<n;i++) {
      cin>>vect[i];
      mp[vect[i]]=false;
    }
    vector<int>grp_of_anagram;
    for(int i=0;i<n;i++) {
      if(mp[vect[i]]==false) {
        int count1=1;
        mp[vect[i]]=true;
        for(int j=i+1;j<n;j++) {
          if(is_anagram(vect[i],vect[j])) {
            mp[vect[j]]=true;
            count1++;
          }
        }
        grp_of_anagram.push_back(count1);
      }
    }
    sort(grp_of_anagram.begin(),grp_of_anagram.end());
    for(int i=0;i<grp_of_anagram.size();i++) {
      cout<<grp_of_anagram[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
