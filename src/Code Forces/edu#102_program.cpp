// Problem Statement: https://codeforces.com/contest/1473/problem/D/

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
#define unmp unordered_map
#define pqi priority_queue<int>
#define pq priority_queue
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

struct Data
{
    int mx, mn, add;
    Data(int mx = 0, int mn = 0, int add = 0) : mx(mx), mn(mn), add(add) {}
};

Data operator+(const Data &a, const Data &b)
{
    return Data(std::max(a.mx, a.add + b.mx), std::min(a.mn, a.add + b.mn), a.add + b.add);
}

void harry()
{
    int n, m;
    ii2(n, m);
    string s;
    cin >> s;
    vector<Data> a(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
            a[i] = Data(1, 0, 1);
        else
            a[i] = Data(0, -1, -1);
    }
    vector<Data> pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + a[i];
    for (int i = n - 1; i >= 0; i--)
        suf[i] = a[i] + suf[i + 1];
    while (m--)
    {
        int l, r;
        ii2(l, r);
        l--;
        auto v = pre[l] + suf[r];
        cout << v.mx - v.mn + 1 << "\n";
    }
    ravireddy07;
}

int main()
{
    int t;
    ii(t);
    while (t--)
        harry();
    return 0;
}
