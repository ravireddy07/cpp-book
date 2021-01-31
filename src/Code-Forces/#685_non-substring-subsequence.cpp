#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void test()
{
    lli n, q;
    scanf("%lld%lld", &n, &q);
    string str;
    cin >> str;
    lli l, r;
    bool flag;
    for (int i = 0; i < q; i++)
    {
        flag = 0;
        scanf("%lld%lld", &l, &r);
        for (int j = 0; j < l - 1; j++)
            if (str[j] == str[l - 1])
                flag = 1;
        for (int j = r; j < n; j++)
            if (str[j] == str[r - 1])
                flag = 1;

        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
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
