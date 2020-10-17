// https://atcoder.jp/contests/abc180/tasks/abc180_c

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int main()
{
    ll x;
    cin >> x;
    vector<ll> result;
    ll i = 1;
    while (i * i <= x)
    {
        if (x % i == 0)
        {
            result.push_back(i);
            if (x / i != i)
                result.push_back(x / i);
        }
        i++;
    }
    sort(result.begin(), result.end());
    for (ll k = 0; k < result.size(); ++k)
        cout << result[k] << endl;
    return 0;
}