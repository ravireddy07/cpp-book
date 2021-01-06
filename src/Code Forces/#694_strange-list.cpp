// Problem Statement: https://codeforces.com/contest/1471/problem/B/

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
#define ill(a) scanf("%lld", &a)
#define ill2(a, b) scanf("%lld%lld", &a, &b)
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define Pii pair<int, int>
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define pqi priority_queue<int>
#define pq priority_queue
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

void harry1()
{
    int n, x, in;
    ill2(n, x);
    vector<ll> v;
    for (ll i = 0; i < n; ++i)
    {
        ill(in);
        v.pb(in);
    }
    int addTimes;
    ll sum = 0;
    while (1)
    {
        if (v[in] % x != 0 || in == v.size())
            break;
        else
        {
            addTimes = v[in] / x;
            for (ll j = 0; j < x; ++j)
                v.pb(addTimes);
            sum += v[in];
            v.erase(v.begin(), v.begin() + 1);
        }
    }
    for (in; in < v.size(); ++in)
        sum += v[in];
    printf("%lld\n", sum);
    ravireddy07;
}

// Accepted Solution
void harry()
{
    int n, x, in;
    ii2(n, x);
    vector<Pii> v;
    for (int i = 0; i < n; ++i)
        ii(in), v.pb(Pii(in, 1));

    ll sum = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int u = v[i].first, k = v[i].second;
        if (u % x != 0)
            break;
        else
            v.push_back(Pii(u / x, k * x)), ++n;
    }

    for (int i = 0; i < v.size(); ++i)
        sum += v[i].first * v[i].second;

    printf("%lld\n", sum);
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
