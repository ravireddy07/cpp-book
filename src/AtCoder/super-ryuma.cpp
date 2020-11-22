// Problem Statemnet: https://atcoder.jp/contests/abc184/tasks/abc184_c

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int ans = 3;
    if (r1 == r2 && c1 == c2)
        ans = min(ans, 0);
    if (r1 + c1 == r2 + c2)
        ans = min(ans, 1);
    if (r1 - c1 == r2 - c2)
        ans = min(ans, 1);
    if (abs(r1 - r2) + abs(c1 - c2) <= 3)
        ans = min(ans, 1);
    if ((r1 % 2 == r2 % 2) && (c1 % 2 == c2 % 2))
        ans = min(ans, 2);
    if ((r1 % 2 != r2 % 2) && (c1 % 2 != c2 % 2))
        ans = min(ans, 2);
    if (abs((r1 + c1) - (r2 + c2)) <= 4)
        ans = min(ans, 2);
    if (abs((r1 - c1) - (r2 - c2)) <= 4)
        ans = min(ans, 2);
    cout << ans << endl;
}
