// Problem Statement: https://www.codechef.com/MARCH21B/problems/COLGLF4

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void rv(vector<ll> &v)
{
    int n = v.size();
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}

void pv(vector<ll> v)
{
    int n = v.size();
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << "\n";
}

void pyn(int i)
{
    if (i == 1)
        cout << "YES"
             << "\n";
    else
        cout << "NO"
             << "\n";
}

float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> city(n);
    vector<pair<pair<int, int>, pair<int, int>>> wire(m);
    vector<pair<float, int>> dist(m);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        city[i] = {x, y};
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        wire[i] = {{a, b}, {c, d}};
        dist[i] = {distance(a, b, c, d), i};
    }

    sort(dist.begin(), dist.end());
    int least = dist[0].second;
    vector<pair<int, int>> res(m);
    for (int i = 0; i < m; i++)
    {
        if (i != least)
            res[i] = {1e6 - wire[i].second.first, 1e6 + 1 - wire[i].second.second};
        else
            res[i] = {-1 - wire[i].first.first, 0 - wire[i].first.second};
    }
    for (int i = 0; i < m; i++)
        cout << res[i].first << " " << res[i].second << "\n";

    return;
}

int main()
{
    solve();
    return 0;
}
