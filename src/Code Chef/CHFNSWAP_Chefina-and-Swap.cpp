#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long int

ll Combi(ll n, ll r, ll p)
{
    ll Temp[r + 1];
    memset(Temp, 0, sizeof(Temp));
    Temp[0] = 1;
    for (ll i = 0; i <= n; ++i)
        for (ll j = min(i, r); j > 0; --j)
            Temp[j] = (Temp[j] + Temp[j - 1]) % p;
    return Temp[r];
}

ll CombiFun(ll n, ll r, ll p)
{
    if (r == 0)
        return 1;
    ll a = n % p, b = r % p;
    return (CombiFun(n / p, r / p, p) * Combi(a, b, p)) % p;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, ar;
        cin >> n;
        if (((n * (n + 1)) / 2) % 2 == 1)
            ar = 0;
        else
        {
            ll sum = 0, c = 0;
            ll half = (n * (n + 1)) / (2 * 2);
            for (ll i = n; i >= 1; i--)
            {
                sum += i;
                c++;
                if (sum == half)
                {
                    ar = CombiFun(n - c, 2, 1000000000007) + CombiFun(c, 2, 1000000000007) + c;
                    break;
                }
                else if (sum > half)
                {
                    ar = c;
                    break;
                }
            }
        }
        cout << ar << endl;
    }
    return 0;
}

/*
ll prob(ll sm)
{
    long double res = sqrtl(1ul + 4 * (sm));
    res -= 1.0;
    res /= 2.0;
    return (ll)res;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 0 || n == 1 || n == 2)
        {
            cout << 0 << endl;
            continue;
        }
        ll temp = (n * (n + 1)) / 2;
        if (temp % 2 != 0)
        {
            cout << 0 << endl;
            continue;
        }
        ll pos = prob(t1);

        if ((temp / 2) == (pos * (pos + 1) / 2))
            cout << (pos * (pos - 1ul)) / 21 + ((n - pos) * (n - pos - 1ul)) / 21 + (n - pos) << endl;
        else
            cout << n - pos << endl;
    }
    return 0;
}
*/