// Problem Statement: https://codeforces.com/contest/1455/problem/B

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test()
{
    int X;
    cin >> X;
    int jumps = 0;

    while (X > 0)
        X -= ++jumps;

    if (X == -1)
        jumps++;

    cout << jumps << '\n';
}

void test()
{
    ll x;
    cin >> x;
    if (x == 1)
    {
        cout << "1\n";
        return;
    }
    ll s = 0, i = 0;
    for (i = 1; i <= x; ++i)
    {
        s += i;
        if (s >= x)
            break;
    }
    if ((s - x) == 1)
        cout << i + (s - x) << '\n';
    else
        cout << i << '\n';
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        test();
    return 0;
}
