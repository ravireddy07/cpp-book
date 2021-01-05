// Problem Statement: https://www.codechef.com/JAN21B/problems/ANTSCHEF/

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

ll n, m, negCnt, posCnt;
#define maxx 500020;
ll points[500020];

void harry()
{
    ill(n);
    posCnt = 0, negCnt = 0;
    for (int i = 0; i < n; ++i)
    {
        ill(m);
        // int points[m];
        points[m] = {0};
        for (int j = 0; j < m; ++j)
        {
            ill(points[j]);
            if (points[j] > 0)
                posCnt++;
            else
                negCnt++;
        }
    }
    ll res = posCnt * negCnt;

    printf("%lld", res);
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
