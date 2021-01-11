// Problem Statement: https://www.codechef.com/JAN21B/problems/COOLSBST/

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#pragma GCC optimze("Ofast")
#include "bits/stdc++.h"
using namespace std;
using base = complex<double>;
#define mod 998244353
#define M2 998244353
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define inf 1e18
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define all(c) c.begin(), c.end()
#define sz(s) (int)s.size()

#define o_set(T) tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//to delete an element
//s.erase(s.find_by_order(s.order_of_key(ele)));
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

// To remove randomization use 0 below:
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int ri(int x)
{ // from [0, n-1]
    return uniform_int_distribution<int>(0, x - 2)(rng);
}

inline ld rf()
{ // from [0, 1]
    return uniform_real_distribution<ld>(0, 1)(rng);
}

int add(int x, int y)
{
    x += y;
    if (x >= mod)
    {
        x -= mod;
    }
    return x;
}

int sub(int x, int y)
{
    x -= y;
    if (x < 0)
        x += mod;
    return x;
}

int mul(int x, int y)
{
    return (long long)x * y % mod;
}

/*SOME BITMASK KNOWLEDGE
1)x & (x - 1):sets the last one bit of x to zero
power of two exactly when x & (x ? 1) = 0.
2)x & -x:sets all the one bits to zero, except last one bit
3)x | (x - 1):inverts all the bits after the last one bit*/

//debugging template
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl

const int N = 1e6 + 5;
const int Q = 1e6 + 5;
const int M = 1e6 + 5;
const int SZ = 150;

ll all[N], odd[N], special[N];

inline int64_t gilbertOrder(int x, int y, int pow, int rotate)
{
    if (pow == 0)
    {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? (
                               (y < hpow) ? 0 : 3)
                         : (
                               (y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query
{
    int l, r, idx;
    int64_t ord;

    inline void calcOrder()
    {
        ord = gilbertOrder(l, r, 21, 0);
    }

} qr[Q];

inline bool operator<(const Query &a, const Query &b)
{
    return a.ord < b.ord;
}

ll ff[N], inv[N];

ll power(ll a, ll b) //a is base, b is exponent
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 1)
        return (power(a, b - 1) * a) % mod;
    ll q = power(a, b / 2);
    return (q * q) % mod;
}

void compute()
{
    ff[0] = 1;
    fl(i, 1, N)
    {
        ff[i] = (1LL * i * ff[i - 1]) % mod;
    }
    inv[N - 1] = power(ff[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
    {
        inv[i] = (1LL * (i + 1) * inv[i + 1]) % mod;
    }
}

ll C(ll n, ll r)
{
    if (n < r or n < 0 or r < 0)
        return 0;
    return (1LL * ((1LL * ff[n] * inv[r]) % mod) * inv[n - r]) % mod;
}

int n;
int freq[M];
long long ans[Q];
long long cur = 0;

bool comp(struct Query &d1, struct Query &d2)
{
    int b1 = d1.l / SZ;
    int b2 = d2.l / SZ;
    if (b1 != b2)
        return b1 < b2;
    else
        return (b1 & 1) ? d1.r < d2.r : d1.r > d2.r;
}

inline void addL(int x, ll n)
{
    //x++;
    cur += C(n, x);
    cur %= mod;
}

inline void removeL(int x, ll n)
{
    //x++;
    cur -= C(n, x);
    cur += mod;
    cur %= mod;
}

inline void addR(int x, ll a)
{
    cur *= 2;
    cur %= mod; //p2(C(x,a), a);
    cur += (-C(x, a) + 1 + 2 * mod) % mod;
    cur %= mod;
    //p1(cur);
}

ll chut = power(2, mod - 2);

inline void removeR(int x, ll a)
{
    cur -= 1;
    cur %= mod;
    cur += C(x, a);
    cur += mod;
    cur %= mod;
    cur *= chut;
    cur %= mod;
}

ll qq = 0;

void mo()
{
    sort(qr + 1, qr + qq + 1, comp);
    int l = 1, r = 1; // ans = 1;
    cur = 1;
    for (int i = 1; i <= qq; i++)
    { //  p2(qr[i].l, qr[i].r);
        while (l < qr[i].l)
            addL(++l, r);
        while (l > qr[i].l)
            removeL(l--, r);
        while (r < qr[i].r)
            addR(r++, l);
        while (r > qr[i].r)
            removeR(--r, l);
        //p2(qr[i].l, qr[i].r); p1(cur);
        ans[qr[i].idx] = cur;
    }
}

int spf[N];

void sieve()
{
    spf[1] = 1;

    for (int i = 2; i < N; i++)
        spf[i] = i;

    for (int i = 4; i < N; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<ll> getf(int x)
{
    vector<ll> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

ll cntodd(ll l, ll r)
{
    ll ans = r - l;
    ans /= 2;
    if (r % 2 != 0 || l % 2 != 0)
        ans += 1;
    return ans;
}

int l, r, a, b;
map<pll, ll> mpp;

ll f(ll l, ll r, ll a, ll b)
{
    ll f1 = all[r] - all[l - 1], f2 = odd[r] - odd[l - 1];
    ll x1 = cntodd(l, r), num = r - l + 1;
    if (a > num)
        return 0;
    ll x2 = num - x1 - special[r] + special[l - 1];

    ll aa = ans[mpp[{num, b}]] - ans[mpp[{num, a}]] + mod + C(num, a);
    aa %= mod;
    ll bb = ans[mpp[{x1, min(x1, b)}]] - ans[mpp[{x1, a}]] + mod + C(x1, a);
    bb %= mod; //p1(bb);
    ll c = (bb + C(x1, a - 1)) % mod;
    c -= C(x1, b);
    c += mod;
    c %= mod; //p1(c);
    ll d = aa - C(num - 1, a - 1) + C(num - 1, b) + mod;
    d %= mod;
    d *= power(2, mod - 2);
    d %= mod;
    d += C(num - 1, a - 1);
    d %= mod;
    d -= C(num - 1, b);
    d += mod;
    d %= mod;
    ll e = bb - C(x1 - 1, a - 1) + C(x1 - 1, b) + mod;
    e %= mod;
    e *= power(2, mod - 2);
    e %= mod;
    e += C(x1 - 1, a - 1);
    e %= mod;
    e -= C(x1 - 1, b);
    e += mod;
    e %= mod;

    ll one = aa;
    one += mod;
    one %= mod;
    ll two = one - (bb);
    two += mod;
    two %= mod; //p1(two);

    ll four = (two - (x2 * (c) % mod) % mod + mod) % mod;
    ll lol = ((f1 % mod) * (d % mod)) % mod;
    ll rofl = lol - ((f2 % mod) * (e) % mod) % mod;
    rofl += mod;
    rofl %= mod;
    // p1(one); p1(two); p1(four); p1(lol); p1(rofl);
    ll ans = 0;
    ans += one;
    ans %= mod;
    ans += two;
    ans %= mod;
    ans += four;
    ans %= mod;
    ans += lol;
    ans %= mod;
    ans += rofl;
    ans %= mod;
    return ans;
}

vector<pair<pll, pll>> q;

void solve()
{
    int n;
    scanf("%d", &n);
    ll curr = 1;
    set<pll> s;
    fl(i, 1, n + 1)
    {
        scanf("%d %d %d %d", &l, &r, &a, &b);
        int x1 = cntodd(l, r), num = r - l + 1;
        int x2 = num - x1 - special[r] + special[l - 1];
        q.pb({{l, r}, {a, b}});
        s.insert({num, max(0, a)});
        s.insert({num, b});
        s.insert({x1, max(0, a)});
        s.insert({x1, min(x1, b)});
        //  s.insert({x1, max(0LL ,a - 1)}); s.insert({x1, min(x1, b - 1)}); s.insert({num - 1, max(0LL, a - 1)}); s.insert({num - 1, b - 1});
        //s.insert({x1 - 1, max(0LL, a - 1)}); s.insert({x1 - 1, min(x1 - 1, b - 1)});
    }
    ans[0] = 1;
    for (auto i : s)
    {
        if (i.ss == 0)
        {
            mpp[i] = 0;
            continue;
        }
        qr[curr].r = i.ff;
        qr[curr].l = i.ss;
        qr[curr].idx = curr;
        mpp[i] = curr;
        curr++;
    }
    qq = curr - 1;
    mo();
    fl(i, 1, qq + 1) ans[i]++;
    fl(i, 0, n)
    {
        cout << (f(q[i].ff.ff, q[i].ff.ss, q[i].ss.ff, q[i].ss.ss)) << endl;
    }
}

signed main()
{
    // std::ios::sync_with_stdio(false);
    int T = 1;
    //cin>>T;
    sieve();
    compute();
    odd[0] = all[0] = special[0] = 0;
    fl(i, 1, N)
    {
        odd[i] = all[i] = special[i] = 0;
        vll v = getf(i);
        map<ll, ll> m;
        for (auto it : v)
            m[it]++;
        for (auto it : m)
        {
            if (it.ff == 2)
            {
                if (it.ss > 1)
                    special[i]++;
            }
            else
            {
                all[i] += it.ss;
                if (i & 1LL)
                    odd[i] += it.ss;
            }
        }
        odd[i] += odd[i - 1];
        all[i] += all[i - 1];
        special[i] += special[i - 1];
    }
    //  fl(i,1,9) cout << odd[i] << ' ';
    // cin.ignore(); must be there when using getline(cin, s)
    while (T--)
    {
        solve();
    }
    return 0;
}
