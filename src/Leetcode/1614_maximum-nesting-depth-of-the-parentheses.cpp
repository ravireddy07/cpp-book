// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        vector<int> t;
        int res=0, temp;
        for(int i=0; i<s.length(); i++)
            if(s[i] >= 48 && s[i] <= 57)
                t.push_back(i);
        
        for(int i=0; i<t.size(); i++) {
            temp = 0;
            for(int j=t[i]; j>=0; j--) {
                if(s[j] == '(')
                    temp += 1;
                else if(s[j] == ')')
                    temp -= 1;
            }
            if(temp > res)
                res = temp;
        }
        return res;        
    }
};

int main() {
  Solution a;
  cout << a.maxDepth("(1+(2*3)+((8)/4))+1") << endl;
  return 0;
}