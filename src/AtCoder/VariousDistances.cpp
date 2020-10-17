// https://atcoder.jp/contests/abc180/tasks/abc180_b

#include <bits/stdc++.h>
#define ll long long int
#include <iomanip>
using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll t;
    for (ll i = 0; i < n; i++)
    {
        cin >> t;
        v.push_back(abs(t));
    }

    ll max = v[0];
    ll m = v[0];
    double e = v[0] * v[0];

    for (ll i = 1; i < n; ++i)
    {
        if (max < v[i])
            max = v[i];
        m += v[i];
        e += v[i] * v[i];
    }
    cout << m << endl;
    cout << setprecision(15);
    cout << sqrt(e) << endl;
    cout << max;
    return 0;
}