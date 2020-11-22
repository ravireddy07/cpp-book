// Problem Statement: https://atcoder.jp/contests/abc184/tasks/abc184_b

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int n, x;
    string s;

    scanf("%d%d", &n, &x);
    cin >> s;
    int res = x;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
            res += 1;
        else if (s[i] == 'x' and res > 0)
            res -= 1;
    }
    printf("%d\n", res);
    return 0;
}
