#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector<int> cnt1(26);
    vector<int> cnt2(26);
    for (int i = 0; i < n; i++)
    {
        cnt1[a[i] - 'a']++;
        cnt2[b[i] - 'a']++;
    }
    for (int i = 0; i < 25; i++)
    {
        if (cnt1[i] < cnt2[i])
        {
            cout << "No" << endl;
            return;
        }
        if (cnt1[i] == cnt2[i])
        {
            continue;
        }
        int diff = cnt1[i] - cnt2[i];
        if (diff % k != 0)
        {
            cout << "No" << endl;
            return;
        }
        cnt1[i + 1] += diff;
    }
    if (cnt1[25] == cnt2[25])
    {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
