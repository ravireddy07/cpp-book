// Problem Statement: https://codeforces.com/contest/1454/problem/B

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// TLE Solution. O(N*N)
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

// Need to be Tested. O(N)
void test()
{
    int n;
    scanf("%d", &n);

    if (n == 1)
    {
        int temp;
        scanf("%d", &temp);
        printf("%d\n", temp);
        return;
    }

    int v[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int cMin = INT_MAX;
    sort(v, v + n);

    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[i - 1])
            continue;
        else if (i == 1 and v[i] != v[i - 1])
            cMin = min(min(v[i], v[i - 1]), cMin);
        else if (v[i] != v[i - 1] and v[i - 1] != v[i - 2])
            cMin = min(min(v[i], v[i - 1]), cMin);
        else
            cMin = min(cMin, v[n - 1]);
    }
    printf("%d\n", (cMin != INT_MAX) ? cMin : -1);
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
