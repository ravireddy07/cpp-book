// Problem Statement: https://codeforces.com/contest/1499/problem/A

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#define ll long long int
#define yes printf("YES\n")
#define no printf("NO\n")
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k1, k2;
        scanf("%d%d%d", &n, &k1, &k2);
        int w, b;
        scanf("%d%d", &w, &b);

        int res = 0;
        res = 2 * n;
        if (k1 + k2 == res)
            yes;
        else if (k1 == 0 and k2 == 0)
            no;
        else
        {
            if (k1 != 0)
                res--;
            if (k2 != 0)
                res--;
            res -= w;
            res -= b;
            if (res > 0)
                yes;
            else
                no;
        }
    }
    return 0;
}
