// Problem Statement: https://www.codechef.com/JAN21B/problems/BILLRD/
// Explanation: https://youtu.be/bUb3fItMfAg

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

void harry()
{
    int n, k, x, y;
    ii2(n, k);
    ii2(x, y);

    if (x == y)
        printf("%d %d\n", n, n);

    else
    {
        map<int, pair<int, int>> mp;
        if (x < y)
        {
            swap(x, y);
            mp[1] = {y + n - x, n};
            mp[2] = {n, y + n - x};
            mp[3] = {x - y, 0};
            mp[4] = {0, x - y};
        }
        else
        {
            mp[1] = {n, y + n - x};
            mp[2] = {y + n - x, n};
            mp[3] = {0, x - y};
            mp[4] = {x - y, 0};
        }
        int effColl = ((k - 1) % 4) + 1;

        cout << mp[effColl].first << " " << mp[effColl].second << "\n";
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
