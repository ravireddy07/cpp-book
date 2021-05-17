// Problem Statement: https://www.codechef.com/MAY21B/problems/VPATH

#include <bits/stdc++.h>
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double ld;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(x) ((long long)x.size())
#define fr(a, b, c) for (int a = b; a <= c; a++)
#define frev(a, b, c) for (int a = c; a >= b; a--)
#define rep(a, b, c) for (int a = b; a < c; a++)
#define trav(a, x) for (auto &a : x)
#define all(con) con.begin(), con.end()
#define done(x)            \
    {                      \
        cout << x << endl; \
        return;            \
    }
#define mini(x, y) x = min(x, y)
#define maxi(x, y) x = max(x, y)
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
//const int mod = 998244353;
const int mod = 1e9 + 7;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef map<int, int> mii;
typedef set<int> si;
typedef set<pair<int, int>> spii;
typedef queue<int> qi;
uniform_int_distribution<int> rng(0, 1e9);

//DEBUG FUNCTIONS START
#define cerr cout
void __print(int x)
{
    cerr << x;
}
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifdef LOCAL
#define deb(x...) _print(x)
#else
#define deb(x...)
#endif
// DEBUG FUNCTIONS END

const int N = 1e5 + 5;

vi g[N];
int dp[N];
int ans;

void dfs(int v, int p)
{

    dp[v] = 1;
    (ans += 1) %= mod;
    int x = 0;

    trav(to, g[v])
    {

        if (to == p)
            continue;

        dfs(to, v);
        (dp[v] += 2 * dp[to]) %= mod;
        (ans += (2 * x + 1) * dp[to]) %= mod;
        (x += dp[to]) %= mod;
    }
}

void solve()
{

    int n;
    cin >> n;

    fr(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, -1);

    cout << ans << endl;

    fr(i, 1, n)
    {
        g[i].clear();
        dp[i] = 0;
    }
    ans = 0;
}

signed main()
{

#ifdef LOCAL
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}

int powm(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int divide(int a, int b)
{
    return (a % mod) * powm(b % mod, mod - 2) % mod;
}
