// Problem Statement:  https://codeforces.com/contest/1457/problem/B

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void test()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> v(n);
    for (auto &x : v)
        scanf("%d", &x);
    int ans = INT_MAX, cnt, l;

    for (int j = 1; j <= 100; j++)
    {
        cnt = 0;
        l = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != j)
                l++;
            else if (l)
                l++;
            if (l == k)
            {
                cnt++;
                l = 0;
            }
        }
        if (l)
            cnt++;
        ans = min(ans, cnt);
    }
    printf("%d\n", ans);
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
