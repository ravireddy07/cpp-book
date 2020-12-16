// Problem Statement: https://codeforces.com/contest/1437/problem/A

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test()
{
    ll l, r;
    cin >> l >> r;
    ll res = r + 1;
    if (((l % res + res / 2) > r) && (r % res + res / 2) > r)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        test();
    return 0;
}
