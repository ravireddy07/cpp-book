// https://atcoder.jp/contests/abc180/tasks/abc180_d

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    // X Y  A B
    // 4 20 2 10
    ll str = x;
    ll exp = 0;

    while (str < y)
    {
        str *= 2;
        exp += 1;
        if (str < y)
        {
            str += b;
            exp += 1;
        }
    }
    cout << exp - 1 << endl;
    return 0;
}