// Problem Statement: https://www.codechef.com/OCT20B/problems/CHEFEZQ

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int in[n];
        for (int i = 0; i < n; ++i)
            cin >> in[i];
        if (n == 1)
        {
            cout << (in[0] / k) + 1 << endl;
            continue;
        }

        ll total = 0;
        ll day = 0;
        int dayFound = 0;
        for (int i = 0; i < sizeof(in) / sizeof(in[0]); ++i)
        {
            day += 1;
            if (in[i] + total < k)
            {
                cout << day << endl;
                dayFound = 1;
                break;
            }
            total = (in[i] + total) - k;
        }
        if (!dayFound)
        {
            day += total / k;
            cout << day + 1 << endl;
        }
    }
    return 0;
}
