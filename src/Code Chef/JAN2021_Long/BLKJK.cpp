// Problem Statement: https://www.codechef.com/JAN21B/problems/BLKJK/

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
#define Pii pair<int, int>
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define pqi priority_queue<int>
#define pq priority_queue
#define yes printf("YES\n")
#define no printf("NO\n")
#define mod 998244353
#define all(v) v.begin(), v.end()
using namespace std;

template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}

int s, n, x, y, t, stat, cnt;
vi v1, v2;

void harry()
{
    v1.clear(), v2.clear();
    ii3(n, x, y);
    int a[n];
    s = 0, stat = 0;
    for (int i = 0; i < n; i++)
    {
        ii(a[i]);
        if (x > a[i])
        {
            v1.pb(a[i]);
            s += a[i];
        }
        else if (y < a[i])
            v2.pb(a[i]);
    }
    if ((v1.size() + v2.size()) == n)
    {
        if (s < x)
        {
            stat = 1;
            printf("-1\n");
        }
    }

    cnt = 0;
    if (stat == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cnt += a[i];
            if ((cnt >= x) && (cnt <= y))
            {
                stat = 1;
                printf("0\n");
                break;
            }
        }
    }
    if (stat == 0)
    {
        int end = 0, bit, temp;
        for (int i = 0; i < n; i++)
        {
            end += a[i];
            if (end > y)
            {
                bit = i;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if ((x <= a[i]) && (a[i] <= y))
            {
                stat = 1;
                printf("1\n");
                break;
            }
        }

        if (stat == 0)
        {
            for (int i = bit; i < n; i++)
            {
                if (a[i] <= y)
                {
                    for (int j = 0; j <= bit; j++)
                    {
                        temp = a[i];
                        for (int k = 0; k < n; k++)
                        {
                            if (k != j && k != i)
                                temp = temp + a[k];
                            if ((x <= temp) && (temp <= y))
                            {
                                stat = 1;
                                printf("1\n");
                                break;
                            }
                        }
                        if (stat == 1)
                            break;
                    }
                }
                if (stat == 1)
                    break;
            }
        }
    }
    if (stat == 0)
        printf("2\n");
    ravireddy07;
}

int main()
{
    ii(t);
    while (t--)
        harry();
    return 0;
}
