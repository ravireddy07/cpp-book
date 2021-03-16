// Problem Statement: https://www.codechef.com/MARCH21B/problems/COLGLF4

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#define int long long
#define pb push_back
#define x first
#define y second
#define mk(a, b) make_pair(a, b)
#define rr return 0
#define sqr(a) ((a) * (a))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class value, class cmp = less<value>>
using ordered_set = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template <class value, class cmp = less_equal<value>>
using ordered_multiset = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template <class key, class value, class cmp = less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

/// find_by_order()
/// order_of_key()
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int randll(int l = INT_MIN, int r = INT_MAX)
{
    return uniform_int_distribution<int>(l, r)(rng);
}

const int INF = 1e9 + 1, MOD = 1e9 + 7; /// think
const ll LINF = 2e18;

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
inline bool inside(int x, int y, int n, int m)
{
    return 0 <= x && 0 <= y && x < n && y < m;
}

template <class T>
bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template <class T>
bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }

inline int mul(int a, int b, int m = MOD)
{
    return ((ll)a * b) % m;
}

inline int binpow(int a, int n, int m = MOD)
{
    int ans = 1;
    for (; n; n >>= 1)
    {
        if (n & 1)
            ans = mul(ans, a, m);
        a = mul(a, a, m);
    }
    return ans;
}

inline void add(int &a, int x, int m = MOD)
{
    a += x;
    if (a >= m)
        a -= m;
    if (a < 0)
        a += m;
}

inline int sum(int a, int b, int m = MOD)
{
    a += b;
    if (a >= m)
        a -= m;
    if (a < 0)
        a += m;
    return a;
}

inline int inv(int x, int m = MOD)
{
    return binpow(x, m - 2, m); /// only if m is prime
}

vector<int> f, fi;

inline void precalc_f(int n, int m = MOD)
{
    f.resize(n);
    fi.resize(n);
    f[0] = 1;
    for (int i = 1; i < n; i++)
    {
        f[i] = mul(f[i - 1], i, m);
    }
    fi[n - 1] = inv(f[n - 1], m);
    for (int i = n - 2; i >= 0; i--)
    {
        fi[i] = mul(fi[i + 1], i + 1, m);
    }
}

inline int A(int n, int k, int m = MOD)
{
    return mul(f[n], fi[n - k], m);
}

inline int C(int n, int k, int m = MOD)
{
    return mul(A(n, k), fi[k], m);
}

vector<vector<int>> edge;
vector<int> center;
int n;
inline int dfs(int v, int p = -1)
{
    int cnt = 1;
    bool ok = true;
    for (int to : edge[v])
    {
        if (to == p)
            continue;
        int s = dfs(to, v);
        if (s > n / 2)
            ok = false;
        cnt += s;
    }
    if (n - cnt > n / 2)
        ok = false;
    if (ok)
    {
        center.pb(v);
    }
    return cnt;
}

inline pii dfs_sort(int v, int p = -1)
{
    int cnt = 0, res = 1;
    for (int to : edge[v])
    {
        if (to == p)
            continue;
        pii t = dfs_sort(to, v);
        res = mul(mul(res, t.y), C(cnt + t.x, cnt));
        cnt += t.x;
    }
    return {cnt + 1, res};
}

inline int solution(int v)
{
    return dfs_sort(v).y;
}

vector<int> cn;
inline void dfs1(int v, int p = -1)
{
    cn[v] = 1;
    for (int to : edge[v])
    {
        if (to == p)
            continue;
        dfs1(to, v);
        cn[v] += cn[to];
    }
}

inline void solve()
{
    for (auto &i : edge)
    {
        i.clear();
    }
    edge.clear();
    center.clear();
    int k;
    cin >> n >> k;
    assert(k <= n);
    if (n == 1)
    {
        cout << "1 1\n";
        return;
    }
    edge.resize(n);
    for (int i = 1, a, b; i < n; i++)
    {
        cin >> a >> b;
        --a, --b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs(0);
    sort(all(center));
    reverse(all(center));
    assert(sz(center) <= 2 && sz(center) > 0);
    if (sz(center) == 2 || k == 1)
    {
        cout << center[k - 1] + 1 << ' ' << solution(center[k - 1]) << '\n';
        return;
    }
    vector<pii> have;
    cn.clear();
    cn.resize(n);
    dfs1(center[0]);
    for (int to : edge[center[0]])
    {
        have.pb({cn[to], to});
    }
    sort(all(have));
    reverse(all(have));
    //    cout << "ans\n";
    for (auto &i : have)
    {
        cout << i.y + 1 << ' ' << solution(i.y) << '\n';
        break;
    }
    //    cout << "======\n";
}

const int N = 5e5 + 11;

main()
{
    precalc_f(N);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
