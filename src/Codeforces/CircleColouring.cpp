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
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];

        int first = a[0];
        cout << first;
        int prev = first;
        for (int i = 1; i < n; i++)
        {
            for (int x : {a[i], b[i], c[i]})
            {
                if (x != prev && x != first)
                {
                    prev = x;
                    cout << " " << x;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}