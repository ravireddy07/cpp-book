#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
#define p 1000000007
ll fac[100001];
void factorial();
ll power(ll x, ll y);
ll modInverse(ll n);
ll nCrModPFermat(ll n, ll r);

void factorial()
{
    fac[0] = 1;
    for (ll i = 1; i < 100001; i++)
        fac[i] = ((fac[i - 1] % p) * (i % p)) % p;
    return;
}

ll power(ll x, ll y)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = ((res % p) * (x % p)) % p;
        y = y >> 1;
        x = ((x % p) * (x % p)) % p;
    }
    return res % p;
}

ll modInverse(ll n)
{
    return power(n, p - 2) % p;
}

ll nCrModPFermat(ll n, ll r)
{
    if (r == 0)
        return 1;
    return ((((fac[n] % p) * (modInverse(fac[r]) % p) % p) % p) * ((modInverse(fac[n - r]) % p) % p)) % p;
}

int main()
{
    factorial();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        ll total = power(2, n) % p;
        ll temp = a[0], counter = 1;
        for (ll i = 1; i < n; i++)
        {
            if (a[i] > temp)
            {
                temp = a[i];
                counter = 1;
            }
            else if (a[i] == temp)
                counter++;
        }

        if (counter % 2 == 1)
        {
            cout << total % p << endl;
            continue;
        }
        temp = power(2, (n - counter)) % p;
        ll comb = nCrModPFermat(counter, counter / 2) % p;
        ll value = ((temp % p) * (comb % p)) % p;
        ll ans = (total % p - value % p + p) % p;
        cout << ans % p << endl;
    }
    return 0;
}