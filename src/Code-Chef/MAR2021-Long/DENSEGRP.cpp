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

const int INF = 1e9 + 1, MOD = 998244353; /// think
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

vector<vector<pii>> t;
vector<int> ss;
inline void upd(int v, int tl, int tr, int l, int r, int x, int y)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[v].pb({x, y});
        ++ss[v];
        return;
    }
    int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm, l, min(r, tm), x, y);
    upd(v << 1 | 1, tm + 1, tr, max(tm + 1, l), r, x, y);
    ss[v] = ss[v << 1] + ss[v << 1 | 1] + sz(t[v]);
}
vector<pii> to_go;

inline void go(int v, int tl, int tr, int pos)
{
    if (!ss[v])
        return;
    ss[v] -= sz(t[v]);
    for (pii o : t[v])
    {
        to_go.pb(o);
    }
    t[v].clear();
    if (tl == tr)
    {
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
    {
        go(v << 1, tl, tm, pos);
    }
    else
    {
        go(v << 1 | 1, tm + 1, tr, pos);
    }
    ss[v] = ss[v << 1] + ss[v << 1 | 1] + sz(t[v]);
}

inline void solve()
{
    to_go.clear();
    ss.clear();
    for (auto &i : t)
    {
        i.clear();
    }
    t.clear();
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> have = {x, y};
    vector<int> a(m), b(m), c(m), d(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        have.push_back(a[i]);
        have.push_back(b[i]);
        have.push_back(c[i]);
        have.push_back(d[i]);
    }
    sort(all(have));
    have.erase(unique(all(have)), have.end());
    auto get_c = [&](int x) {
        return int(lower_bound(all(have), x) - have.begin());
    };
    x = get_c(x);
    y = get_c(y);
    for (int i = 0; i < m; i++)
    {
        a[i] = get_c(a[i]);
        b[i] = get_c(b[i]);
        c[i] = get_c(c[i]);
        d[i] = get_c(d[i]);
    }
    int s = sz(have);
    t.resize(4 * s);
    ss.resize(4 * s);
    vector<int> dist(s, INF);
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    for (int i = 0; i < m; i++)
    {
        upd(1, 0, s - 1, a[i], b[i], c[i], d[i]);
    }
    set<int> coord;
    for (int i = 0; i < s; i++)
    {
        if (i == x)
            continue;
        coord.insert(i);
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        to_go.clear();
        go(1, 0, s - 1, v);
        for (auto &i : to_go)
        {
            while (true)
            {
                auto it = coord.lower_bound(i.x);
                if (it != coord.end() && *it <= i.y)
                {
                    dist[*it] = dist[v] + 1;
                    q.push(*it);
                    coord.erase(it);
                }
                else
                    break;
            }
        }
    }
    if (dist[y] >= INF)
    {
        cout << "-1\n";
    }
    else
    {
        cout << dist[y] << '\n';
    }
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
    {
        solve();
    }
}
