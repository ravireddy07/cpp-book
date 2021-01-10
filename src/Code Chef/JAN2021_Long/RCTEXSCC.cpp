// Problem Statement: https://www.codechef.com/JAN21B/problems/RCTEXSCC/

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

ll n, m, k, q;
const ll maxx = 1e5 + 10;
ll dpm1[maxx + 1];
ll dpm2[maxx][2];
#define mod 998244353

ll mInverse(ll base, ll expo /*, ll m*/)
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
        //ll dpm1[n + 1];
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
        {
            /*
            q = mInverse(k, 2 * n);
            q = mInverse(q, mod - 2);
            */
            printf("%lld\n", q);
            ravireddy07;
        }
        //ll dp[n][2];
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
        printf("%lld\n", (res * q) % mod); //p1(dp[1][1]);
    }
    ravireddy07;
}

/********************* WA ************************/
// const int N = 1e5;
// int n, m, k;
// ll x, y, p, q;
// int factorial[N], inverse[N];

/*
ll power(ll a, ll b, ll m);
ll inv(ll a, ll m);
int help(int n, int r);
void pre();

ll inv(ll a, ll m)
{
    return power(a, m - 2, m);
}

ll power(ll a, ll b, ll m)
{
    int x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y);
            if (x > m)
                x %= m;
        }
        y = y * y;
        if (y > m)
        {
            y %= m;
            b /= 2;
        }
    }
    return x;
} */

/*
int help(int n, int r)
{
    int x = factorial[n] % mod;
    x = (x * inverse[n - r]) % mod;
    x = (x * inverse[r]) % mod;
    return x % mod;
}

void pre()
{
    factorial[0] = inverse[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        factorial[i] = (factorial[i - 1] * i) % mod;
        factorial[i] = power(factorial[i - 1], mod - 2, mod) % mod;
    }
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

        for (int i = 1; i <= n - 1; i++)
            res += i * ((fact(n - 1) / fact(i - 1)) * (k * pow((k - 1), i - 1)));

        ll dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[1] = k;
        for (ll i = 2; i < n + 1; ++i)
        {
            dp[i] += dp[i - 1];
            dp[i] %= mod;
            dp[i] += ((k - 1) * (dp[i - 1] + (power(k, i - 1, i)))) & mod;
            dp[i] %= mod;
        }

        cout << "check: before pre" << endl;
        pre();
        cout << "check: pre" << endl;
        for (int i = 0; i < n; i++)
        {
            int x = help(n - 1, i) % mod;
            y = ((((i + 1) * x) % mod) * k) % mod * power(k - 1, i, mod) % mod;
            p = (p + y) % mod;
        }
        cout << "check: for loop" << endl;
        q = (power(k, n, mod) % mod);
        cout << "check: q" << endl;
        ll ans = (p * inv(q, mod)) % mod;

        //  % 998244353;

        printf("%lld\n", ans);
        // 1 8 3    665496241
    }
}
*/

int main()
{
    harry();
    return 0;
}
