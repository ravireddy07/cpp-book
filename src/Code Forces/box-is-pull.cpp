// https://codeforces.com/contest/1428/problem/A

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2 && y1 == y2)
        cout << 0 << endl;
    else if (x1 == x2 || y1 == y2)
        cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    else
        cout << abs(x1 - x2) + abs(y1 - y2) + 2 << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        test();
    return 0;
}