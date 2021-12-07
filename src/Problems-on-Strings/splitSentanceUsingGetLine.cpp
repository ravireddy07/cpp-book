// Problem Statement: Split the Sentance into words or seperate a sentance by
// char occurance.

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string str1, str2;

  // Take the Input(sentance) like: 'Hello Harry, How are you ?'
  getline(cin, str1);

  stringstream X(str1);

  char seperator = ' ';

  while (getline(X, str2, seperator)) {
    // It displays the text without the seperator(eliminates seperator)
    cout << str2 << "\n";
  }
  return 0;
}
