// Problem Statement: https://codeforces.com/contest/1455/problem/B

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test()
{
    int X;
    cin >> X;
    int jumps = 0;

    while (X > 0)
        X -= ++jumps;

    if (X == -1)
        jumps++;

    cout << jumps << '\n';
}

void test()
{
    int n;
    scanf("%d", &n);
    int cur = 0;
    int i = 1;
    while (cur < n)
    {
        cur += i;
        //cout << i << " " << cur << endl;
        i++;
    }
    //cout << endl;

    if (cur == n + 1)
        printf("%d\n", i);
    else
        printf("%d\n", i - 1);
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
