// Problem Statement: https://www.codechef.com/JAN21B/problems/RCTEXSCC/
// Explanation: https://youtu.be/CitIf168mYk

/*
Formula: 

        for (int i = 1; i <= n - 1; i++)
            res += i * ((fact(n - 1) / fact(i - 1)) * (k * pow((k - 1), i - 1)));
*/

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
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define unmp unordered_map
#define pqi priority_queue<int>
#define pq priority_queue
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
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

//  Accepted Solution
ll n, m, k, q;
const ll maxx = 1e5 + 10;
ll dpm1[maxx + 1];
ll dpm2[maxx][2];
#define mod 998244353

ll mInverse(ll base, ll expo)
{
    if (expo == 0)
        return 1;
    if (expo == 1)
        return base;
    if (expo % 2 == 1)
        return (mInverse(base, expo - 1) * base) % mod;
    ll value = mInverse(base, expo / 2);
    return (value * value) % mod;
}

void harry()
{
    ill2(m, n);
    ill(k);
    q = 0;
    if (k == 1 and m == 1)
        printf("1\n");
    else if (m == 1)
    {
        memset(dpm1, 0, sizeof n + 1);
        dpm1[1] = k;
        for (ll i = 2; i < n + 1; ++i)
        {
            dpm1[i] += dpm1[i - 1];
            dpm1[i] %= mod;
            dpm1[i] += ((k - 1) * (dpm1[i - 1] + (mInverse(k, i - 1)))) % mod;
            dpm1[i] %= mod;
        }
        q = mInverse(k, n);
        q = mInverse(q, mod - 2);
        printf("%lld\n", (dpm1[n] * q) % mod);
    }
    else if (m == 2)
    {
        q = mInverse(k, 2 * n);
        q = mInverse(q, mod - 2);
        if (k == 1)
            printf("%lld\n", q);
        else
        {
            memset(dpm2, 0, sizeof dpm2[n][2]);
            dpm2[0][0] = k;
            dpm2[0][1] = (2 * k * (k - 1)) % mod;
            for (int i = 1; i < n; ++i)
            {
                dpm2[i][0] += ((k - 1) * (dpm2[i - 1][0] + (k * mInverse(k, 2 * (i - 1))) % mod) % mod) % mod;
                dpm2[i][0] %= mod;
                dpm2[i][0] += dpm2[i - 1][0];
                dpm2[i][0] %= mod;
                dpm2[i][0] += (2LL * dpm2[i - 1][1]) % mod;
                dpm2[i][0] += ((k - 2) * (dpm2[i - 1][1] + (((k * (k - 1)) % mod) * mInverse(k, 2 * (i - 1))) % mod) % mod) % mod;
                dpm2[i][0] %= mod;
                dpm2[i][1] += ((k - 1) * (dpm2[i - 1][0] + (k * mInverse(k, 2 * (i - 1))) % mod) % mod) % mod;
                dpm2[i][1] %= mod;
                dpm2[i][1] += ((k - 1) * (dpm2[i - 1][0] + (k * mInverse(k, 2 * (i - 1))) % mod) % mod) % mod;
                dpm2[i][1] %= mod;
                dpm2[i][1] += ((((k - 2) * (k - 1)) % mod) * (dpm2[i - 1][0] + (2 * k * mInverse(k, 2 * (i - 1))) % mod) % mod) % mod;
                dpm2[i][1] %= mod;
                dpm2[i][1] += dpm2[i - 1][1];
                dpm2[i][1] %= mod;
                dpm2[i][1] += ((((k - 2)) % mod) * (dpm2[i - 1][1] + (((k * (k - 1)) % mod) * mInverse(k, 2 * (i - 1))) % mod) % mod) % mod;
                dpm2[i][1] %= mod;
                dpm2[i][1] += ((((k - 2)) % mod) * (dpm2[i - 1][1] + (((k * (k - 1)) % mod) * mInverse(k, 2 * (i - 1))) % mod) % mod) % mod;
                dpm2[i][1] %= mod;
                dpm2[i][1] += ((((k - 2)) % mod) * (dpm2[i - 1][1] + ((2 * (k * (k - 1)) % mod) * mInverse(k, 2 * (i - 1))) % mod) % mod) % mod;
                dpm2[i][1] %= mod;
                dpm2[i][1] += ((((k - 1)) % mod) * (dpm2[i - 1][1] + ((2 * (k * (k - 1)) % mod) * mInverse(k, 2 * (i - 1))) % mod) % mod) % mod;
                dpm2[i][1] %= mod;
                dpm2[i][1] += ((((k - 2) * (max(k - 3, 0LL))) % mod) * (dpm2[i - 1][1] + ((2 * (k * (k - 1)) % mod) * mInverse(k, 2 * (i - 1))) % mod) % mod) % mod;
                dpm2[i][1] %= mod;
            }
            ll res = (dpm2[n - 1][0] + dpm2[n - 1][1]) % mod;
            printf("%lld\n", (res * q) % mod);
        }
    }
    ravireddy07;
}

/********************************************************/
// Optimal Solution
#define MOD 998244353

ll add(ll x, ll y)
{
    ll res = x + y;
    return (res >= MOD ? res - MOD : res);
}

ll mul(ll x, ll y)
{
    ll res = x * y;
    return (res >= MOD ? res % MOD : res);
}

ll sub(ll x, ll y)
{
    ll res = x - y;
    return (res < 0 ? res + MOD : res);
}

ll power(ll x, ll y)
{
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

ll mod_inv(ll x) { return power(x, MOD - 2); }

void harry()
{
    ll m, n, k;
    ill3(m, n, k);
    ll E_e, E_f = 1, E_1 = 1, E_v, ans;
    E_v = mul(n, m);
    E_e = mul(add(mul(n, sub(m, 1)), mul(m, sub(n, 1))), mod_inv(k));
    if (m == 2)
        E_f = add(E_f, mul(sub(n, 1), mod_inv(power(k, 3))));
    ans = sub(add(E_v, E_f), add(E_e, E_1));
    printf("%lld\n", ans);
    ravireddy07;
}

int main()
{
    harry();
    return 0;
}
