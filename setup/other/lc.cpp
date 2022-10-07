// https://leetcode.com/problems/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dp[11] = {0};
  vector<int> f(vector<int> a)
  {
    map<int, int> cnt;
    for (int i : a)
      cnt[i]++;
    sort(a.begin(), a.end(), [&](int x, int y) {
      make_pair(cnt[x], -x) < make_pair(cnt[y], -y);
    });

    return a;
  }
};

int main()
{
  Solution a; // 3 4 4 2 2 1 1 1
  vector<int> in = {1, 2, 3, 2, 1, 1, 4, 4};
  //vector<vector<int>> in = {{}, {}, {}};
  //cout << a.f(in) << endl;
  vector<int> show = a.f(in);
  cout << "[";
  for (int i = 0; i < show.size(); i++)
  {
    if (i == show.size() - 1)
      cout << show[i];
    else
      cout << show[i] << ", ";
  }
  cout << "]" << endl;
  return 0;
}
