// Problem Statement: https://codeforces.com/contest/1472/problem/C/

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

int t, n, curSum, jump;

void harry()
{
    ii(n);
    int ar[n];
    int res[n];
    vector<int> wait;
    int ok = 1;
    for (int i = 0; i < n; i++)
    {
        ii(ar[i]);
        res[i] = 0;
    }

    for (int i = n; i >= 0; --i)
    {
        curSum = 0;
        jump = i + ar[i - 1];
        curSum = ar[i - 1];
        if (jump <= n)
            curSum += res[jump - 1];
        res[i - 1] += curSum;
    }
    /*
    for (int i = 1; i <= n; i++)
        cout << res[i - 1] << " ";
    */
    cout << *max_element(res, res + n) << "\n";
    ravireddy07;
}

int main()
{
    ii(t);
    while (t--)
        harry();
    return 0;
}
