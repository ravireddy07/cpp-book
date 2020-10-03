// https://www.codechef.com/OCT20B/problems/CHEFEZQ

#include <bits/stdc++.h>
using namespace std;

void tets()
{
    int n, k;
    cin >> n >> k;
    int v[n];
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int total = 0;
    int left = 0;
    int days = 0, s = 1;
    for (int i = 0; i < sizeof(v) / sizeof(v[0]); ++i)
    {
        total += v[i];
        if (total < k)
        {
            cout << days + 1 << endl;
            s = 0;
            break;
        }
        else
            total -= k;
        days++;
    }

    if (total > k)
    {
        days += total / k;
        cout << days + 1 << endl;
    }
    else if (s)
        cout << days << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int v[n];
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        if (n == 1)
        {
            cout << (v[0] / k) + 1 << endl;
            continue;
        }

        int total = 0;
        int left = 0;
        int day = 0, s = 1;
        for (int i = 0; i < sizeof(v) / sizeof(v[0]); ++i)
        {
            day += 1;
            if (v[i] + left < k)
            {
                cout << day << endl;
                s = 0;
                break;
            }
            total = v[i] + left;
            left = total - k;
        }
        if (s)
        {
            day += left / k;
            cout << day + 1 << endl;
        }
    }
    return 0;
}