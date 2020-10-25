// https://codeforces.com/contest/1436/problem/A

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    if (sum == m)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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