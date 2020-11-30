// Problem Statement: https://codeforces.com/contest/1455/problem/C

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// Accepted Solution
void test()
{
    lli x, y;
    scanf("%lld %lld", &x, &y);
    printf("%lld %lld\n", x - 1, y);
    return;
}

void test()
{
    lli xx, yy;
    cin >> xx >> yy;
    lli xw = 0, yw = 0;
    bool s = 0;
    lli res1, res2;
    for (int i = 0; i < 2; i++)
    {
        if (i)
            s = 0;
        else
            s = 1;

        lli x = xx, y = yy;
        xw = 0;
        yw = 0;
        while (1)
        {
            if (x == 0)
            {
                yw++;
                break;
            }
            else if (y == 0)
            {
                xw++;
                break;
            }
            else if (s)
            {
                x--;
                s = s ? 0 : 1;
            }
            else if (!s)
            {
                y--;
                s = s ? 0 : 1;
            }
        }
        if (x != 0)
        {
            xw += x;
            xw--;
        }
        if (y != 0)
        {
            yw += y;
            yw--;
        }
        if (!i)
        {
            res1 = xw;
            res2 = yw;
        }
        cout << xw << " " << yw << endl;
    }

    res1 = max(res1, xw);
    res2 = max(res2, yw);

    cout << res1 << " " << res2 << endl;
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
