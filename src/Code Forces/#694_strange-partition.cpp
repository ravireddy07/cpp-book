// Problem Statement: https://codeforces.com/contest/1471/problem/A/

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

ll t, n, x, sum, in, maxScore, minScore;

//Logic Based Solution
void harry1()
{
    ii2(n, x);
    maxScore = 0, minScore = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        ii(in);
        sum += in;
        if (in % x)
            maxScore += (in / x) + 1;
        else
            maxScore += (in / x);
    }

    if (sum % x)
        minScore = (sum / x) + 1;
    else
        minScore = (sum / x);
    printf("%lld %lld\n", minScore, maxScore);
    ravireddy07;
}

// Formula based
void harry()
{
    ill2(n, x);
    maxScore = 0, minScore = 0;
    for (int i = 0; i < n; i++)
    {
        ii(in);
        maxScore += (in + x - 1) / x;
        minScore += in;
    }
    minScore = (minScore + x - 1) / x;
    printf("%lld %lld\n", minScore, maxScore);
    ravireddy07;
}

int main()
{
    ii(t);
    while (t--)
        harry();
    return 0;
}
