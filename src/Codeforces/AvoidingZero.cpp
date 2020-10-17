// https://codeforces.com/contest/1427/problem/A

#include <bits/stdc++.h>
using namespace std;

void test()
{
    int n;
    cin >> n;
    vector<int> in(n);
    int sum = 0, ps = 0, ns = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
        sum += in[i];
        if (in[i] > 0)
            ps += in[i];
        else
            ns += in[i];
    }
    if (!sum)
    {
        cout << "NO" << endl;
        return;
    }
    vector<int> res;
    sort(in.begin(), in.end());

    if (ps > abs(ns))
    {
        for (int i = 0; i < n; i++)
            if (in[i] > 0)
                res.push_back(in[i]);
        for (int i = 0; i < n; i++)
            if (in[i] < 0)
                res.push_back(in[i]);
    }
    else
    {
        for (int i = 0; i < n; i++)
            if (in[i] < 0)
                res.push_back(in[i]);
        for (int i = 0; i < n; i++)
            if (in[i] > 0)
                res.push_back(in[i]);
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        if (i < res.size())
            cout << res[i] << " ";
        else
            cout << 0 << " ";
    }
    cout << endl;
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