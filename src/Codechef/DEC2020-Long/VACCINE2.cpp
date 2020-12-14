// Problem Statement: https://www.codechef.com/DEC20B/problems/VACCINE2

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void test()
{
    int n, d;
    scanf("%d %d", &n, &d);
    int v[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    double g1 = 0, g2 = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= 80 || v[i] <= 9)
            g1++;
    }
    g2 = abs(g1 - n);
    while (g1 > 0)
    {
        res++;
        g1 -= d;
    }
    while (g2 > 0)
    {
        res++;
        g2 -= d;
    }
    printf("%d\n", res);
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
