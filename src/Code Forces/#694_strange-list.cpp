// Problem Statement: https://codeforces.com/contest/1472/problem/D/

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

ll n, x, in, sum, addTimes;
void harry1()
{
    ill2(n, x);
    vector<ll> v;
    for (ll i = 0; i < n; ++i)
    {
        ill(in);
        v.pb(in);
    }

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
    printf("%d\n", sum);
    ravireddy07;
}

// Accepted Solution
void harry()
{
    ill2(n, x);
    vector<ll> given;
    for (ll i = 0; i < n; ++i)
    {
        ill(in);
        given.pb(in);
    }

    vector<ll> neww(n, 1);
    for (int i = 0; i < given.size(); ++i)
    {
        if (given[i] % x != 0)
            break;
        else
        {
            given.pb(given[i] / x);
            neww.pb(x * neww[i]);
        }
    }

    sum = 0;
    for (int i = 0; i < given.size(); ++i)
        sum += (neww[i] * neww[i]);
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
