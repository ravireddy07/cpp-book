// https://www.codechef.com/OCT20B/problems/REPLESX

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int findI(vector<int> in, int n, int x, int p)
{
    int min = 100000000, minp;
    for (int i = 0; i < n; i++)
    {
        if (in[i] == x)
        {
            if (abs(p - i) < min)
            {
                min = abs(p - i);
                minp = i;
            }
        }
    }
    return minp;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, p, k;
        cin >> n >> x >> p >> k;

        vector<int> in(n);
        for (int i = 0; i < n; ++i)
            cin >> in[i];

        sort(in.begin(), in.end());
        int index = findI(in, n, x, p);
        int count = 0;

        if (in[index] != x)
        {
            in[k - 1] = x;
            sort(in.begin(), in.end());
            count++;
        }

        if (in[p - 1] == x)
        {
            cout << 0 + count << endl;
            continue;
        }

        if (p < k && in[p - 1] < x)
        {
            cout << -1 << endl;
            continue;
        }

        if (p > k && in[p - 1] > x)
        {
            cout << -1 << endl;
            continue;
        }
        index = findI(in, n, x, p) + 1;
        cout << abs(p - index) + count << endl;
    }
    return 0;
}