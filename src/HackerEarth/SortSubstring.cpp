/*
7
abccaab
*/

#include<bits/stdc++.h>
using namespace std;

int solve (int n, char s[]) {
   int count=0, aa, cc;
   for (int len = 1; len <= n; len++) 
	{
      for (int i = 0; i <= n - len; i++) 
		{
         int j = i + len - 1;
         aa=0;
         cc==0;
         for (int k = i; k <= j; k++) {
            if(s[k] == 'a') {
                  aa++;
               }
               else if(s[k] == 'c') {
                  cc++;
               }
               else {
                  continue;
               }
         }
         if(aa > cc) {
            count++;
        }
		}
         
	}
   return count;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    char s[n];
    cin>>s;

    int out_;
    out_ = solve(n, s);
    cout << out_;
}
