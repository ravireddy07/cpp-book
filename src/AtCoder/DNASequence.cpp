/*
We have given A, B.
where, X+Y = A.
       X-Y = B. We have to find X,Y
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<char> u(256);
    u['A'] = 0;
    u['T'] = 1;
    u['C'] = 2;
    u['G'] = 3;

    vector<vector<int>> sum(4, vector<int>(n + 1));
    for (int i = 0; i < n; i++)
    {
        int c = u[s[i]];
        for (int k = 0; k < 4; k++)
        {
            sum[k][i + 1] = sum[k][i];
            if (c == k)
                sum[k][i + 1] += 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n + 1; j++)
        {
            vector<int> count(4);
            for (int k = 0; k < 4; k++)
                count[k] = sum[k][j] - sum[k][i];
            if (count[0] == count[1] && count[2] == count[3])
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}