// Problem Statement: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6

// Partilly Accepted
#include <bits/stdc++.h>
#define lli long long int
using namespace std;

bool test(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!i and (int) s[i] % 2 == 0)
            return 1;
        else if ((int)s[i] % 2 == 0 && i % 2 == 0)
            return 1;
        else if ((int)s[i] % 2 != 0 and i % 2 != 0)
            return 1;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    lli l, r;
    lli res;
    for (int tt = 0; tt < t; tt++)
    {
        scanf("%lld%lld", &l, &r);
        res = 0;

        for (lli i = l; i <= r; i++)
        {
            if (i < 10)
            {
                if (i % 2 == 0)
                    res++;
            }
            else
                res += (test(to_string(i))) ? 1 : 0;
        }
        printf("Case #%d: %lld\n", tt + 1, ((r - l) + 1) - res);
    }
    return 0;
}
