// Problem Statement: https://codeforces.com/contest/1472/problem/A

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

ll cards, n, w, h;
void harry()
{
    ill2(w, h);
    ill(n);
    if (w % 2 == 1 && h % 2 == 1 && n > 1)
        no;
    else
    {
        cards = 1;
        while (w % 2 == 0 || h % 2 == 0)
        {
            if (cards >= n)
                break;
            if (w % 2 == 0 && h % 2 == 0)
            {
                if (w >= h)
                    w /= 2;
                else
                    h /= 2;
                cards *= 2;
            }
            else if (w % 2 == 0)
            {
                w /= 2;
                cards *= 2;
            }
            else if (h % 2 == 0)
            {
                h /= 2;
                cards *= 2;
            }
        }
        cards >= n ? yes : no;
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
