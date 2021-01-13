// Problem Statement: https://www.codechef.com/JAN21B/problems/ORAND/
// Explanation: https://youtu.be/Xsj_hz21B9I

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
#define ill(a) scanf("%lld", &a)
#define ill2(a, b) scanf("%lld%lld", &a, &b)
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define Pii pair<int, int>
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define pqi priority_queue<int>
#define pq priority_queue
#define yes printf("YES\n")
#define no printf("NO\n")
using namespace std;

template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}

/*
// Partial Solution
ll t, n, m, x;
set<ll> V;
stack<ll> tempStore;
vector<ll> a, b;
void harry()
{
    V.clear();
    a.clear();
    b.clear();
    tempStore.empty();

    V.insert(0);
    tempStore.push(0);

    ill2(n, m);
    for (ll i = 0; i < n; ++i)
        ill(x), a.pb(x);
    for (ll i = 0; i < m; ++i)
        ill(x), b.pb(x);

    while (!tempStore.empty())
    {
        x = tempStore.top();
        tempStore.pop();
        for (ll i = 0; i < n; ++i)
        {
            if (!V.count(x | a[i]))
            {
                V.insert(x | a[i]);
                tempStore.push(x | a[i]);
            }
        }
        for (ll i = 0; i < m; ++i)
        {
            if (!V.count(x & b[i]))
            {
                V.insert(x & b[i]);
                tempStore.push(x & b[i]);
            }
        }
    }
    printf("%lu\n", V.size());
    ravireddy07;
}
*/

#define MOD 998244353
const int N = 1 << 20;
const int M = 100005;

ll a[N], b[N], c[N];
int ext, bit;

ll mul(ll x, ll y)
{
    ll res = x * y;
    return (res >= MOD ? res % MOD : res);
}

ll power(ll x, ll y)
{
    if (y < 0)
        return 1;
    ll res = 1;
    x %= MOD;
    while (y)
    {
        if (y & 1)
            res = mul(res, x);
        y >>= 1;
        x = mul(x, x);
    }
    return res;
}

ll inv(ll x) { return power(x, MOD - 2); }

void fwht_or(ll *f, int opt)
{
    for (int l = 2, k = 1; l <= ext; l <<= 1, k <<= 1)
    {
        for (int i = 0; i < ext; i += l)
        {
            for (int j = 0; j < k; j++)
            {
                f[i + j + k] = (f[i + j + k] + f[i + j] * opt) % MOD;
            }
        }
    }
}

void fwht_and(ll *f, int opt)
{
    for (int l = 2, k = 1; l <= ext; l <<= 1, k <<= 1)
    {
        for (int i = 0; i < ext; i += l)
        {
            for (int j = 0; j < k; j++)
            {
                f[i + j] = (f[i + j] + f[i + j + k] * opt) % MOD;
            }
        }
    }
}

void harry()
{
    int t, n, m, x;
    int mx = 0;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    ii2(n, m);
    for (ll i = 1; i <= n; i++)
    {
        ii(x);
        ++a[x];
        mx = max(mx, x);
    }

    a[0] = c[0] = 1;
    for (ll i = 1; i <= m; i++)
    {
        ii(x);
        ++b[x];
        mx = max(mx, x);
    }

    bit = 0;
    while ((1 << bit) <= mx)
        ++bit;

    bit = min(bit + 1, 20);
    ext = 1 << bit;
    b[ext - 1] = 1;

    fwht_or(a, 1);
    for (ll i = 0; i <= ext - 1; i++)
        a[i] = power(a[i], 1800);
    fwht_and(b, 1);
    for (ll i = 0; i <= ext - 1; i++)
        b[i] = power(b[i], 1800);

    for (ll i = 0; i <= 20; i++)
    {
        fwht_or(c, 1);
        for (ll j = 0; j <= ext - 1; j++)
            c[j] = c[j] * a[j] % MOD;
        fwht_or(c, MOD - 1);
        fwht_and(c, 1);
        for (ll j = 0; j <= ext - 1; j++)
            c[j] = c[j] * b[j] % MOD;
        fwht_and(c, MOD - 1);
    }
    int ans = 0;
    for (ll i = 0; i <= ext - 1; i++)
        if (c[i])
            ++ans;
    printf("%d\n", ans);
    ravireddy07;
}

int main()
{
    ll t;
    ill(t);
    while (t--)
        harry;
    return 0;
}
