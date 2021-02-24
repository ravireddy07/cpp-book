// Problem Statement: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b027

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, mxX, mnX, mxY, mnY;
int x[N], y[N];
pair<int, int> a[N];

int calc(int X, int Y)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += abs(x[i] - (X + i)) + abs(y[i] - Y);
    return ans;
}

int ternaryX(int lo, int hi, int y)
{
    while (lo < hi - 5)
    {
        int m1 = (lo * 2 + hi) / 3;
        int m2 = (lo + hi * 2) / 3;
        if (calc(m1, y) < calc(m2, y))
            hi = m2;
        else
            lo = m1;
    }
    int ans = calc(lo, y);
    for (int i = lo + 1; i <= hi; i++)
        ans = min(ans, calc(i, y));
    return ans;
}

int ternaryY(int lo, int hi)
{
    while (lo < hi - 5)
    {
        int m1 = (lo * 2 + hi) / 3;
        int m2 = (lo + hi * 2) / 3;
        if (ternaryX(mnX, mxX, m1) < ternaryX(mnX, mxX, m2))
            hi = m2;
        else
            lo = m1;
    }
    int ans = ternaryX(mnX, mxX, lo);
    for (int i = lo + 1; i <= hi; i++)
        ans = min(ans, ternaryX(mnX, mxX, i));
    return ans;
}

int32_t main()
{
    int t;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        tc++;
        cin >> n;
        mxY = mxX = -1e9;
        mnY = mnX = 1e9;

        for (int i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i];
            a[i].first = x[i];
            a[i].second = y[i];
            mnX = min(mnX, x[i]);
            mxX = max(mxX, x[i]);
            mnY = min(mnY, y[i]);
            mxY = max(mxY, y[i]);
        }
        mnY -= n;
        mxY += n;
        mnX -= n;
        mxX += n;
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
            x[i] = a[i].first, y[i] = a[i].second;
        int ans = ternaryY(mnY, mxY);
        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}
