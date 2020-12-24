// Problem Statement: https://codeforces.com/contest/1459/problem/C

#include <bits/stdc++.h>
#define ll long long
#define sheldon_harry printf("\n")
#define oi(a) printf("%d ", a)
#define oll(a) printf("%lld ", a)
#define ii(a) scanf("%d", &a)
#define ill(a) scanf("%lld", &a)
#define f (i, x, y) for (int i = x; i < y; ++i)
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define yes printf("YES")
#define no printf("NO")
using namespace std;

class cp
{
public:
    ll gcd(ll x, ll y)
    {
        return y == 0 ? x : gcd(y, x % y);
    }

    void test()
    {
        int n, m;
        ii(n);
        ii(m);
        ll a[1000002], b[1000002];

        for (int i = 1; i <= n; ++i)
            ill(a[i]);
        for (int i = 1; i <= m; ++i)
            ill(b[i]);

        sort(a + 1, a + 1 + n);

        ll td = 0;
        for (int i = 1; i < n; i++)
            td = gcd(td, a[i + 1] - a[i]);
        for (int i = 1; i <= m; i++)
            oll(gcd(td, a[1] + b[i]));
        sheldon_harry;
        return;
    }
};

int main()
{
    cp a;
    a.test();
    return 0;
}

/*
Author: Ravi Kanth Gojur
Github: ravireddy07
*/
