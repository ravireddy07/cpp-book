// Problem Statement: https://www.codechef.com/MAY21B/problems/ISS

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

const int N = 4e6 + 2;
namespace sieve {
  vector<int> ps; bool isc[N]; ll phi[N], f[N], e[N];
  void sieve() { phi[1] = f[1] = 1;
    for (int i = 2; i < N; i++) { if (!isc[i]) {
        ps.push_back(i);
        phi[i] = i-1;
        f[i] = 2*i-1;
        e[i] = 1; }
      for (int ip, j = 0; j < ps.size() && (ip=i*ps[j]) < N; j++) {
        isc[ip] = 1;
        if (i % ps[j] == 0) {
          phi[ip] = phi[i] * ps[j];
          int pf = round(powl(ps[j], e[i]));
          f[ip] = (i == pf ? f[i] * ps[j] + phi[ip] : f[i/pf] * f[pf * ps[j]]);
          e[ip] = e[i] + 1; break;
        } else {
          phi[ip] = phi[i] * phi[ps[j]];
          f[ip] = f[i] * f[ps[j]];
          e[ip] = 1; }
      } } }
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  sieve::sieve();

  int T;
  cin >> T;
  while(T--) {
    int k;
    cin >> k;
    int n = 4*k + 1;
    ll f = sieve::f[n];
    cout << n + (f - n) / 2 - 1 << nl;
  }

  return 0;
}
