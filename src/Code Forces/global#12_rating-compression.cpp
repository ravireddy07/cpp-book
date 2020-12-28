// Problem secondtatement:  https://codeforces.com/contest/1450/problem/D

#include <bits/stdc++.h>
using namespace std;

// TLE secondolution
int perm(vector<int> ar, int n)
{
    sort(ar.begin(), ar.end());
    if (ar[n - 1] != n)
        return 0;
    for (int i = 1; i < n; i++)
        if (ar[i] == ar[i - 1])
            return 0;
    return 1;
}

void test()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    vector<int> temp;
    while (v.size() > 0)
    {
        printf("%d", perm(v, v.size()));
        temp.erase(temp.begin(), temp.end());

        for (int j = 1; j < v.size(); j++)
            temp.push_back(min(v[j], v[j - 1]));

        v.erase(v.begin(), v.end());
        v = temp;
    }

    printf("\n");
    return;
}

// AC

void test()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> mp;
    string ans(n, '0');
    int mx = 1e9;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mp[a[i]].push_back((i + 1));
        mx = min(mx, a[i]);
    }

    if (mp.size() == n)
        ans[0] = '1';
    int cur = 1;
    int l = 1, r = n;

    for (auto &j : mp)
    {
        if (j.first != cur)
            break;
        ans[n - cur] = '1';
        if ((j.second).size() > 1 || (j.second[0] != l && j.second[0] != r))
        {
            // cout<<j.first<<"\n";
            break;
        }
        ++cur;
        if (j.second[0] == l)
            ++l;
        else
            --r;
    }
    cout << ans << "\n";
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        test();
    return 0;
}
