#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
using namespace std;

set<string> print;

void order(string &str,int i) {
  if(i==str.size())	{
    print.insert(str);
    return;
  }

  for(int j=i;j<str.size();j++)	{
    swap(str[i],str[j]);
    order(str,i+1);
    swap(str[i],str[j]);
  }
}

int main() {
  string str;
  cin>>str;

  order(str,0);

  for(set<string>::iterator i=print.begin();i!=print.end();i++) {
    if((*i)>str) {
      cout<<*i<<endl;
    }
  }
  return 0;
}
