// https://codeforces.com/contest/1428/problem/E

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int t;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        sum += t;
    }

    vector<int> res(k);
    res.assign(k, 0);
    int a = sum / k;
    for (int i = 0; i < k; i++)
        res[i] += a;

    sum -= a * k;

    for (int i = sum - 1; i >= 0; i--)
        res[i] += 1;
    //std::reverse(res.begin(), res.end());

    sum = 0;
    for (int i = 0; i < k; ++i)
        sum += res[i] * res[i];
    cout << sum << endl;
    return 0;
}