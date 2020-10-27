// https://codeforces.com/contest/1437/problem/E

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> ar(n);
    vector<int> sett(k);
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    int res = 0;
    if (k > 0)
    {
        for (int i = 0; i < k; i++)
            cin >> sett[i];
        sort(sett.begin(), sett.end());

        if (k == n)
        {
            cout << -1 << endl;
            return 0;
        }

        for (int i = 0; i < k; i++)
        {
            for (int l = 0; l < n; l++)
            {
                if (ar[l] == sett[i])
                {
                    for (int j = l; j > 0; j--)
                    {
                        if (ar[j] <= ar[j - 1])
                        {
                            ar[j - 1] = ar[j] - 1;
                            res += 1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (ar[i] >= ar[i + 1])
            {
                ar[i + 1] = ar[i] + 1;
                res += 1;
            }
        }
    }
    else
    {
        int m = ar[0], z = 1;
        for (z = 1; z < n; z++)
        {
            if (m > ar[z])
            {
                m = z;
            }
        }
        //

        for (int i = z; i < n - 1; i++)
        {
            if (ar[i] >= ar[i + 1])
            {
                ar[i + 1] = ar[i] + 1;
                res += 1;
            }
        }
        for (int i = z; i > 0; i--)
        {
            if (ar[i] <= ar[i - 1])
            {
                ar[i - 1] = ar[i] - 1;
                res += 1;
            }
        }
    }

    if (res != 0)
        cout << res << endl;
    else
        cout << -1 << endl;
    return 0;
}