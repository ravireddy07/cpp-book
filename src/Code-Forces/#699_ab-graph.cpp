// Problem Statement: https://codeforces.com/contest/1481/problem/D

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

int a[1009][1009];

void harry() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            if (s[j - 1] == 'a') a[i][j] = 1;
            if (s[j - 1] == 'b') a[i][j] = 2;
        }
    }
    if (m % 2 == 1) {
        cout << "YES" << endl;
        for (int i = 1; i <= m + 1; i++)
            cout << i % 2 + 1 << " ";
        cout << endl;
        return;
    }
    if (n == 2 && a[1][2] != a[2][1]) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] == a[j][i]) {
                for (int x = 1; x <= m + 1; x++) {
                    cout << (x % 2 ? i : j) << " ";
                }
                cout << endl;
                return;
            }
        }
    }
    int x, y, z;
    if (a[1][2] == a[2][3]) x = 1, y = 2, z = 3;
    if (a[2][3] == a[3][1]) x = 2, y = 3, z = 1;
    if (a[3][1] == a[1][2]) x = 3, y = 1, z = 2;
    if (m % 4 == 2) {

        for (int i = 1; i <= m / 4; i++)
            cout << x << " " << y << " " << z << " " << y << " ";
        cout << x << " " << y << " " << z << endl;
    }
    else {
        cout << y << " ";
        for (int i = 1; i <= m / 4; i++)
            cout << x << " " << y << " " << z << " " << y << " ";
        cout << endl;
    }
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
