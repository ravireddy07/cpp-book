// Problem Statement: https://codeforces.com/contest/1455/problem/C

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void test()
{
    lli x, y;
    scanf("%lld %lld", &x, &y);
    printf("%lld %lld\n", x - 1, y);
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
