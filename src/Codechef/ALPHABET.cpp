#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int N = 26;
    string a;
    cin >> a;
    vector<bool> v(N, 0);
    for (int p = 0; p < a.size(); p++)
        v[a[p] - 'a'] = 1;
    int t;
    cin >> t;
    while (t--)
    {
        string u;
        cin >> u;
        bool possible(1);
        for (int p = 0; p < u.size(); p++)
            if (!v[u[p] - 'a'])
            {
                possible = 0;
                break;
            }
        string res = (possible ? "Yes" : "No");
        cout << res << endl;
    }
    return 0;
}
