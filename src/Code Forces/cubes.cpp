#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void test()
{
    lli n;
    scanf("%lld", &n);
    vector<int> k(n);

    lli sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
        sum += k[i];
    }

    sort(k.begin(), k.end());
    lli req = k[n - 1] * (n - 1);

    while (req < sum)
        req += (n - 1);

    printf("%lld\n", req - sum);
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
