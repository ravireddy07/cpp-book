// Problem Statement: Find 'n'th  Fibonacci Number

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
 **/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int dp[100000007] = {-1};

int usingDP(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  if (dp[n] != -1)
    return dp[n];
  return dp[n] = usingDP(n - 1) + usingDP(n - 2);
}

int usingRecursion(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return usingRecursion(n - 1) + usingRecursion(n - 2);
}

int usingLoop(int n) {
  int sum = 0;
  int prev = 0;
  int cur = 1;
  n -= 1;
  while (n--) {
    sum += (prev + cur);
    int temp = prev;
    prev = cur;
    cur = (temp + prev);
  }
  return cur;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  //memset(dp, -1, sizeof(dp));

  // Using Loop
  auto a = high_resolution_clock::now();
  cout << "Using Loop: " << usingLoop(n) << "\n";
  auto b = high_resolution_clock::now();
  cout << duration_cast<microseconds>(b - a).count() << " Microsecond\n\n";

  // Using Recursion
  auto c = high_resolution_clock::now();
  cout << "Using Recursion: " << usingRecursion(n) << "\n";
  auto d = high_resolution_clock::now();
  cout << duration_cast<microseconds>(d - c).count() << " Microsecond\n\n";

  // Using DP
  auto f = high_resolution_clock::now();
  cout << "Using DP: " << usingDP(n) << "\n";
  auto e = high_resolution_clock::now();
  cout << duration_cast<microseconds>(e - f).count() << " Microsecond\n\n";

  return 0;
}