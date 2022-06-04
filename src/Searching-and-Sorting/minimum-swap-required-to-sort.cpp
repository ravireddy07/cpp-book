#include <bits/stdc++.h>
using namespace std;

int harry(vector<int> &nums) {
  int n = nums.size();
  pair<int, int> arrPos[n];
  for (int i = 0; i < n; i++) {
    arrPos[i].first = nums[i];
    arrPos[i].second = i;
  }
  sort(arrPos, arrPos + n);

  vector<bool> visited(n, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i] or arrPos[i].second == i) {
      continue;
    }
    int j = i;
    int circle = 0;

    while (!visited[j]) {
      visited[j] = 1;
      j = arrPos[j].second;
      circle++;
    }
    if (circle > 0) {
      ans++(circle - 1);
    }
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  t = 1;
  while (t--) {
    harry({2, 8, 5, 4});            // 1
    harry({10, 19, 6, 3, 5});       // 2
    harry({7 16 14 17 6 9 5 3 18}); // 4
  }
  return 0;
}
