#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        int n, m;
        cin >> n >> m;
        if (m % 2 != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int in[n][2][2];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    cin >> in[i][j][k];
        int res = 0;
        if (n > 1)
            for (int i = 0; i < n; i++)
            {
                if (in[i][0][0] == in[i][1][1] || in[i][0][1] == in[i][1][0])
                    res += 1;
            }
        else
        {
            if (in[0][0][0] == in[0][1][1] && in[0][0][1] == in[0][1][0])
                res += 1;
        }

        if (res > 0 && res < m)
        {
            res = 4;
            cout << "YES" << endl;
        }
        else if (res == m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}