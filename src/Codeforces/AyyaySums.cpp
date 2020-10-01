#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> a(n);
        vector<int> inc;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            if (i > 0 && a[i] > a[i - 1])
            {
                inc.push_back(i);
            }
        }

        if (k == 1)
        {
            if (inc.empty())
                puts("1");
            else
                puts("-1");
        }
        else
        {
            int need = inc.size();
            k--;
            int ans = (need + k - 1) / k;
            printf("%d\n", ans);
        }
    }
    return 0;
}