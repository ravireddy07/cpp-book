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

inline void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    ll sum = 0;
    vector<ll> s(x);
    vector<vector<ll>> a(n, vector<ll>(m));
    int y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> y;
            a[i][j] = y;
            sum += y;
            s[((i % x) - (j % x) + x) % x] += y;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> y;
            a[i][j] -= y;
            sum -= y;
            s[((i % x) - (j % x) + x) % x] -= y;
        }
    }
    bool ok = sum % x == 0;
    for (int i = 1; i < x; i++)
    {
        if (s[i - 1] != s[i])
            ok = false;
    }
    cout << (ok ? "Yes" : "No") << '\n';
}

inline bool solution(vector<vector<ll>> a, int x)
{
    int n, m;
    n = sz(a);
    m = sz(a[0]);
    ll sum = 0;
    vector<ll> s(x);
    int y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            y = a[i][j];
            sum += y;
            s[((i % x) + (j % x)) % x] += y;
        }
    }
    bool ok = sum % x == 0;
    for (int i = 1; i < x; i++)
    {
        if (s[i - 1] != s[i])
            ok = false;
    }
    return ok;
}

main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    //    while (true) {
    //        int x = 3, n, m;
    //        n = randll(3, 4);
    //        m = randll(3, 4);
    //        vector <vector <ll> > a(n, vector <ll> (m));
    //        for (auto &i : a) {
    //            for (auto &j : i) {
    //                j = randll(-5, 5);
    //            }
    //        }
    //        if (solution(a, x)) {
    //            cout << "Yes\n";
    //            for (int i = 0; i < n; i++) {
    //                for (int j = 0; j < m; j++) {
    //                    cout << a[i][j] << ' ';
    //                }
    //                cout << '\n';
    //            }
    //            rr;
    //        }
    //    }
}
