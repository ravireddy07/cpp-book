// Problem Statement: https://codeforces.com/contest/1430/problem/A

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void test()
{
    lli n, c1, c2, h;
    scanf("%lld%lld%lld%lld", &n, &c1, &c2, &h);
    string s;
    cin >> s;
    lli p1 = 0, one = 0, zero = 0; // actual
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            p1 += c1;
            zero++;
        }
        else
        {
            p1 += c2;
            one++;
        }
    }
    lli p2 = n * c1 + one * h;
    lli p3 = n * c2 + zero * h;

    printf("%lld\n", min(p1, min(p2, p3)));
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
