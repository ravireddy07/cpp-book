#include <bits/stdc++.h>
using namespace std;

int dp[100005] = {0};

int fibDP(int n) {
  if (n == 0 or n == 1)
    return n;
  if (dp[n] != 0)
    return dp[n];
  return dp[n] = fibDP(n - 1) + fibDP(n - 2);
}

int main() {
  cout << fibDP(8) << "\n";
  return 0;
}
