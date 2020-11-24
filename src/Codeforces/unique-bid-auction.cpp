// Problem Statement: https://codeforces.com/contest/1454/problem/B

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// TLE Solution
void test()
{
    int n;
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int res = 0, j, m = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (v[i] == v[j] && i != j)
                break;

        if (j == n and v[i] < m)
        {
            res = i + 1;
            m = v[i];
        }
    }
    printf("%d\n", (res == 0) ? -1 : res);
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
