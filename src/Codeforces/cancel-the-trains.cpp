// Problem Statement:  https://codeforces.com/contest/1453/problem/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int nn[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &nn[i]);

        int res = 0, mm;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &mm);
            for (int j = 0; j < n; j++)
            {
                if (mm == nn[j])
                {
                    res++;
                    break;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
