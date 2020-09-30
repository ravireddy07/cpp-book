#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        int n;
        int l;
        cin >> n >> l;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int s = 0, cc = 0;
        int sd = 0, ld = 0, i = 0, j = sizeof(a) / sizeof(a[0]) - 1, tt = l;
        int sc = 1, lc = 1;
        while (s < l)
        {
            cc++;
            if (s == a[i])
            {
                sc++;
                s += sc;
                i++;
            }
            else
            {
                s += sc;
            }

            if (l == a[j])
            {
                j--;
                lc++;
                l -= lc;
            }
            else
            {
                l -= lc;
            }
        }
        cout << (double)(cc) << endl;
    }
    return 0;
}