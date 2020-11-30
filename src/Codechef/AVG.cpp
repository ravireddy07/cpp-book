// Problem Statement : https://www.codechef.com/problems/AVG

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void test1()
{
    int n, k, v;
    scanf("%d %d %d ", &n, &k, &v);
    int temp = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        sum += temp;
    }
    int ans = (v * (n + k) - sum) / k;
    if (ans <= 0 || ((v * (n + k) - sum) % k != 0))
        printf("-1\n");
    else
        printf("%d\n", ans);
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        test1();
    return 0;
}
