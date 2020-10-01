#include <bits/stdc++.h>
using namespace std;

void test()
{
    int n, l;
    scanf("%d%d", &n, &l);
    vector<int> a(n + 2);
    a[0] = 0;
    a[n + 1] = l;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int pos1 = 0, pos2 = n + 1;
    double t1 = 0, t2 = 0;
    double s1 = 1, s2 = 1;
    while (pos1 + 1 < pos2)
    {
        double x = (a[pos1 + 1] - a[pos1]) / s1;
        double y = (a[pos2] - a[pos2 - 1]) / s2;
        if (t1 + x < t2 + y)
        {
            t1 += x;
            pos1++;
            s1++;
        }
        else
        {
            t2 += y;
            pos2--;
            s2++;
        }
    }
    double dist = a[pos2] - a[pos1];
    if (t1 < t2)
    {
        dist -= (t2 - t1) * s1;
    }
    else
    {
        dist -= (t1 - t2) * s2;
    }
    double aa = max(t1, t2) + dist / (s1 + s2);
    printf("%.12lf\n", aa);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        test();
    }
    return 0;
}