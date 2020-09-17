#include <iostream>
using namespace std;

int LCS(string s1, string s2){
  if(s1.size() == 0 or s2.size() == 0){
    return 0;
  }
  if(s1[0] == s2[0]){
    return 1+lcs(s1.substr(1), s2.substr(1));
  }
  else{
    return max(lcs(s1, s2.substr(1)), lcs(s1.substr(1), s2));
  }
}

int main(int argc, char const *argv[])
{
	string a,b;
  cin>>a>>b;

  cout<<LCS(a, b);
	return 0;
}
