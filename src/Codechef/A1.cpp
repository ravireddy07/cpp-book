#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<bool> v(m + 1, 0);
        v[0] = true;
        while (n--)
        {
            int x;
            cin >> x;
            for (int p = m; p >= x; p--)
                v[p] = v[p - x] | v[p];
        }
        string res = (v[m] ? "Yes" : "No");
        cout << res << endl;
    }
    return 0;
}
