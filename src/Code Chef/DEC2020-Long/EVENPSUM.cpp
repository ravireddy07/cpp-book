// Problem Statement: https://www.codechef.com/DEC20B/problems/EVENPSUM

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);

    if (a == 1 and b == 1)
        printf("1\n");
    else if (a % 2 != 0 and b % 2 != 0)
        printf("%lld\n", ((a * b) / 2) + 1);
    else
        printf("%lld\n", (a * b) / 2);
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
