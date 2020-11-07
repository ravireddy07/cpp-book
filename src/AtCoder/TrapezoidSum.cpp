// https://atcoder.jp/contests/abc181/tasks/abc181_b

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> a(n + 1), b(n + 1);
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        scanf("%lld", &b[i]);
    }

    for (int i = 0; i < n; i++)
        for (int j = a[i]; j <= b[i]; j++)
            sum += j;

    printf("%lld\n", sum);
    return 0;
}
