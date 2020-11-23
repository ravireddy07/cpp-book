// Problem Statemnet: https://www.codechef.com/COOK124B/problems/IPCCERT

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    lli n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);

    lli v[n][n];
    lli q[n];

    lli sum, res = 0;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &v[i][j]);
            sum += v[i][j];
        }
        scanf("%lld", &q[i]);
        if (sum >= m and q[i] <= 10)
            res++;
    }

    printf("%lld\n", res);
    return 0;
}
