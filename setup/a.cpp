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

void harry() {
  int n;
  cin >> n;
  int v[n];
  for (int i = 0; i < n; ++i)
    cin >> v[i];
  sort(v, v + n);
  // cout << bin(v, 0, n - 1, 10) << endl;
  return;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  auto start = high_resolution_clock::now();

  int t = 1;
  // cin >> t;
  while (t--)
    harry();

  auto stop = high_resolution_clock::now();
  cout << "\n" << duration_cast<microseconds>(stop - start).count() << " ms";

  return 0;
}
