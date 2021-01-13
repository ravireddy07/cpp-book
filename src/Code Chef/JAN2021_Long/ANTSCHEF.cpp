// Problem Statement: https://www.codechef.com/JAN21B/problems/ANTSCHEF/
// Explanation: https://youtu.be/MuTeQP5IN78

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
#define unmp unordered_map
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define all(v) v.begin(), v.end()
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

const ll N = 1e10;
unmp<ll, ll> dirt;
ll res, n, m, in, temp;

void harry()
{
    dirt.clear();
    ill(n);
    vl ants[n];
    for (int i = 0; i < n; ++i)
    {
        ill(m);
        for (int j = 0; j < m; ++j)
        {
            ill(in);
            dirt[abs(in)]++;
            ants[i].pb(in);
        }
        sort(ants[i].begin(), ants[i].end());
    }

    res = 0; // Partial
    for (auto x : dirt)
        if (x.second > 1)
            res++;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < ants[i].size(); ++j)
        {
            temp = 0;
            if (dirt[abs(ants[i][j])] > 1)
            {
                if (ants[i][j] > 0)
                    temp = ants[i].size() - (j + 1);
                else
                    temp = j;
            }
            else
            {
                if (ants[i][j] > 0)
                    temp = lower_bound(ants[i].begin(), ants[i].end(), -1 * ants[i][j]) - ants[i].begin();
                else
                    temp = ants[i].size() - (upper_bound(ants[i].begin(), ants[i].end(), -1 * ants[i][j]) - ants[i].begin());
            }
            res += temp;
        }
    }
    printf("%lld\n", res);
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
