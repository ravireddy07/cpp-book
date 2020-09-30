/*
n=7
a = {1, 3, 3, 1, 1, 1, 1}
b = {2, 4, 4, 3, 2, 2, 4}
c = {4, 2, 2, 2, 4, 4, 2}

Output: 1 3 4 3 2 4 2

We have to select res[i] from a[i],b[i],c[i] so, that no two adjecent will be equal.
*/

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
        cin >> n;
        int a[n], b[n], c[n], res[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                if (a[i] != res[i - 1])
                    res[i] = a[i];
                else if (b[i] != res[i - 1])
                    res[i] = b[i];
                else if (c[i] != res[i - 1])
                    res[i] = c[i];
            }
            else if (a[i] != a[i + 1])
                res[i] = a[i];
            else if (a[i] != b[i + 1])
                res[i] = a[i];
            else if (a[i] != c[i + 1])
                res[i] = a[i];
        }
        for (int i = 0; i < sizeof(res) / sizeof(res[0]); i++)
        {
            if (i == (sizeof(res) / sizeof(res[0])) - 1)
                cout << res[i];
            else
                cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}