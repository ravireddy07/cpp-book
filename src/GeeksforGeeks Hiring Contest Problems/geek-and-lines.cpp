// Problem Statement:  https://practice.geeksforgeeks.org/contest-problem/geek-and-lines/0/

#include <bits/stdc++.h>
using namespace std;
#define N 100005

int n, a[N], b[N], id[N], bit[N];

void update(int idx, int val)
{
    while (idx <= n)
    {
        bit[idx] = max(bit[idx], val);
        idx += idx & -idx;
    }
}

int pref(int idx)
{
    int ans = 0;
    while (idx > 0)
    {
        ans = max(ans, bit[idx]);
        idx -= idx & -idx;
    }
    return ans;
}

int main()
{

    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;

        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(id, 0, sizeof id);
        memset(bit, 0, sizeof bit);

        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x] = i;
            b[y] = i;
        }

        for (int i = 1; i <= n; i++)
            id[b[i]] = i;

        for (int i = 1; i <= n; i++)
            a[i] = id[a[i]];

        reverse(a + 1, a + n + 1);

        int ans = 1;
        for (int i = 1; i <= n; i++)
        {
            int cur = pref(a[i]) + 1;
            ans = max(ans, cur);
            update(a[i], cur);
        }

        cout << ans << "\n";
    }
}
