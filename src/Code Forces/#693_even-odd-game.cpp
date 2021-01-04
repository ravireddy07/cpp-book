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

int t, n;
vector<int> x, y;
ll alice, bob;

void harry()
{
    ii(n);
    int ar[n];
    x.clear();
    y.clear();
    for (int i = 0; i < n; ++i)
    {
        ii(ar[i]);
        x.push_back(0);
        y.push_back(0);
    }

    for (int i = 1; i <= n; i++)
    {
        if (ar[i - 1] & 1)
            y.push_back(ar[i - 1]);
        else
            x.push_back(ar[i - 1]);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    alice = 0, bob = 0;
    bool turn = 0;
    while (n--)
    {
        if (turn == 0)
        {
            if ((int)x.back() > (int)y.back())
            {
                alice += x.back();
                x.pop_back();
            }
            else
                y.pop_back();
        }
        else
        {
            if ((int)y.back() > (int)x.back())
            {
                bob += y.back();
                y.pop_back();
            }
            else
                x.pop_back();
        }
        turn = !turn;
    }

    (alice == bob) ? printf("Tie\n") : (alice > bob) ? printf("Alice\n") : printf("Bob\n");
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
