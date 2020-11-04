// https://www.codechef.com/LTIME89B/problems/ANDOR

/*
Given an integer x, find two non-negative integers a and b such that (a∧b)+(a∨b)=x, 
where ∧ is the bitwise AND operation and ∨ is the bitwise OR operation.
*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    long long int x;
    scanf("%lld", &x);
    printf("0 %lld\n", x);
    return;
}

void solve1()
{
    long long int x;
    scanf("%lld", &x);
    if (x % 2 == 0)
        printf("%lld %lld\n", (x / 2) + 1, (x / 2) - 1);
    else
        printf("%lld %lld\n", (x / 2), (x / 2) + 1);
    return;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}