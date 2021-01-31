// Problem Statement: https://codeforces.com/contest/1463/problem/B/

#include <bits/stdc++.h>
#define ll long long int
#define oi(a) printf("%d\n", a)
#define oll(a) printf("%lld\n", a)
#define ii(a) scanf("%d", &a)
#define ill(a) scanf("%lld", &a)
#define f(i, x, y) for (int i = x; i < y; ++i)
using namespace std;

class cp
{
public:
    void test()
    {
        int n;
        ii(n);
        vector<ll> a(n);
        vector<ll> b(n, 1), c(n, 1);

        ll p1 = 0, p2 = 0, sum = 0;
        f(i, 0, n)
        {
            ii(a[i]);
            sum += a[i];
            if (i & 1)
            {
                b[i] = a[i];

                p2 += (a[i] - 1) * 2;
            }
            else
            {
                c[i] = a[i];
                p1 += (a[i] - 1) * 2;
            }
        }

        if (p1 <= sum)
            for (auto i : b)
                oi(i);
        else
            for (auto i : c)
                oi(i);

        printf("\n");
    }
};

int main()
{
    cp a;
    int t;
    ii(t);
    while (t--)
        a.test();
    return 0;
}
