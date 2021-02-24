// Problem Statement: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043adc7

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++)
    {
        lli n, k, s;
        scanf("%lld%lld%lld", &n, &k, &s);
        lli res = k;
        lli b = k - s;
        if ((res + b * 2) + (n - k) <= (k + n))
            res = k + b * 2 + (n - k);
        else
            res = k + n;
        printf("Case #%d: %lld\n", tt + 1, res);
    }
    return 0;
}
