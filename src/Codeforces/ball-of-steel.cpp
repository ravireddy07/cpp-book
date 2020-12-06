// Problem Statement:  https://codeforces.com/contest/1450/problem/B

#include <bits/stdc++.h>
using namespace std;
#define intl long long int

void dfs(intl n, vector<intl> &vis, vector<list<intl>> &ar1)
{
    if (vis[n] != -1)
        return;
    vis[n] = 1;
    for (auto it = ar1[n].begin(); it != ar1[n].end(); it++)
        if (vis[*it] == -1)
            dfs(*it, vis, ar1);
}

int main()
{
    intl t;
    cin >> t;
    while (t--)
    {
        intl i, j, n, m, k;
        cin >> n >> k;
        vector<pair<intl, intl>> ar(n);
        for (i = 0; i < n; i++)
            cin >> ar[i].first >> ar[i].second;
        vector<list<intl>> ar1(n);
        intl count2 = 0;
        for (i = 0; i < n; i++)
        {
            intl x1 = ar[i].first;
            intl y1 = ar[i].second;
            intl count1 = 0;
            for (j = 0; j < n; j++)
            {
                intl x2 = ar[j].first;
                intl y2 = ar[j].second;
                intl x = abs(x1 - x2);
                intl y = abs(y1 - y2);
                if (x + y <= k)
                    count1++;
            }
            if (count1 == n)
            {
                count2 = 1;
                break;
            }
        }
        if (count2)
            cout << "1\n";
        else
            cout << "-1\n";
    }
    return 0;
}
