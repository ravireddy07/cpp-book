// Problem Statement:  https://codeforces.com/contest/1457/problem/A/

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void test1()
{
    lli n, m, r, c;
    scanf("%lld %lld %lld %lld", &n, &m, &r, &c);
    printf("%lld\n", max(n - r, r - 1) + max(m - c, c - 1));
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        test1();
    return 0;
}
