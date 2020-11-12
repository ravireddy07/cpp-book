#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void test()
{
    lli n;
    scanf("%lld", &n);
    vector<lli> v(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &v[i]);

    lli m, sum = 0, res = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        m = v[i];
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j] >= m)
                sum += m;
        }
        if (sum > res)
            res = sum;
        sum = 0;
    }
    printf("%lld\n", res);
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
