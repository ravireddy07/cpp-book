// https://www.codechef.com/OCT20B/problems/REPLESX

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, p, k;
        cin >> n >> x >> p >> k;
        if (n == 0 || n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> in(n);
        for (int i = 0; i < n; ++i)
            cin >> in[i];

        sort(in.begin(), in.end());
        // x = 25, p = 1
        // 100 20
        ll count = 0;
        while (in[p - 1] != x && count < n)
        {
            count++;
            in[k - 1] = x;
            sort(in.begin(), in.end());
        }

        if (count == n)
        {
            cout << -1 << endl;
            continue;
        }
        cout << count << endl;
    }
    return 0;
}