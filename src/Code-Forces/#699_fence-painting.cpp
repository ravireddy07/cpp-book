// Problem Statement: https://codeforces.com/contest/1481/problem/C/

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#define ll long long int
#define ravireddy07 return
#define ii(a) scanf("%d", &a)
#define ii2(a, b) scanf("%d%d", &a, &b)
#define ii3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ill(a) scanf("%lld", &a)
#define ill2(a, b) scanf("%lld%lld", &a, &b)
#define ill3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define for1(i, a, b) for (int i = a; i < b; ++i)
#define for2(i, a, b) for (int i = b; i >= a; --i)
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define unmp unordered_map
#define pqi priority_queue<int>
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define yes printf("YES\n")
#define no printf("NO\n")
using namespace std;

template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}

template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (a > b)
        a = b;
    return a;
}


int a[100009], b[100009], c[100009];
vector<int> v[100009];

void harry() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    int ok = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] == c[m]) ok = i;
    }
    if (!ok) {
        no;
        continue;
    }
    int bad = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] != a[i]) v[b[i]].push_back(i), bad++;
    }
    vector<int> ans;
    for (int i = m; i >= 1; i--) {
        if (!v[c[i]].size())
        {
            if (i == m)
                ans.push_back(ok);
            else
                ans.push_back(ans[0]);
            continue;
        }
        ans.push_back(v[c[i]].back());
        v[c[i]].pop_back();
        bad--;
    }
    if (bad)
        no;
    else {
        yes;
        reverse(ans.begin(), ans.end());
        for (int x : ans)
            cout << x << " ";
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
        v[i].clear();

    ravireddy07;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    ii(t);
    while (t--)
        harry();
    return 0;
}
