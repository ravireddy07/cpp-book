// Problem Statement: https://codeforces.com/contest/1466/problem/D

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
using namespace std;

void test()
{
    int n;
    cin >> n;
    vector<int> w(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        ans += w[i];
    }
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        deg[x] += 1;
        deg[y] += 1;
    }
    vector<int> seq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < deg[i] - 1; j++)
        {
            seq.push_back(w[i]);
        }
    }
    sort(seq.rbegin(), seq.rend());
    cout << ans;
    for (int x : seq)
    {
        ans += x;
        cout << " " << ans;
    }
    cout << '\n';
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        test();
    return 0;
}
