// Problem Statement:

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
 **/

#include <bits/stdc++.h>
#define ll long long int
#define ravireddy07 return
#define ii(a) scanf("%d", &a)
#define ii2(a, b) scanf("%d%d", &a, &b)
#define ii3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ill(a) scanf("%lld", &a)
#define ill2(a, b) scanf("%lld%lld", &a, &b)
#define ill3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define for1(i, a, b) for (int i = a; i < b; ++i)
#define for2(i, a, b) for (int i = b; i >= a; --i)
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define unmp unordered_map
#define pq priority_queue
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define yes printf("YES\n")
#define no printf("NO\n")
#define setValue(a, value) memset(a, value, sizeof(a))
using namespace std;
ll MOD = 998244353;

template <typename T, typename T1> T amax(T &a, T1 b) {
  if (b > a)
    a = b;
  return a;
}

template <typename T, typename T1> T amin(T &a, T1 b) {
  if (a > b)
    a = b;
  return a;
}

/*
vector<int> getPermutation(size_t n)
{
        vector<int> res;
        string s = to_string(n);
        sort(s.begin(), s.end());
        do
        {
                res.pb(stoi(s));
                //cout << s << "\n";
        } while (getPermutation(s.begin(), s.end()));
        return res;
}*/

ll fpow(ll base, ll power) {
  ll result = 1;
  while (power > 0) {

    if (power & 1)
      result = (result * base) % MOD;
    base = (base * base) % MOD;
    // power >> = 1;
    power = power / 2;
  }
  ravireddy07 result;
}

void dfs(ll s, vector<vector<ll>> &adj, vector<bool> &vis, vector<ll> &arr) {
  if (vis[s])
    return;
  vis[s] = true;
  arr.pb(s);
  for (auto x : adj[s])
    if (vis[x] == false)
      dfs(x, adj, vis, arr);
  ravireddy07;
}

void bfs(ll x, vector<bool> &vis, vector<vector<ll>> &adlist, vector<ll> &level,
         vector<ll> &parent) {
  queue<ll> q;
  vis[x] = true;
  q.push(x);
  while (!q.empty()) {
    ll s = q.front();
    q.pop();
    // process node s
    for (auto u : adlist[s]) {
      if (vis[u])
        continue;
      vis[u] = true;
      parent[u] = s;
      level[u] = level[s] + 1;
      q.push(u);
    }
  }
  ravireddy07;
}

void harry() {
  cout << "\n";
  ravireddy07;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  auto start = high_resolution_clock::now();

  int t;
  ii(t);
  while (t--)
    harry();

  auto stop = high_resolution_clock::now();
  cout << "\n" << duration_cast<microseconds>(stop - start).count() << " ms";

  return 0;
}
