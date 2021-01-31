// Problem Statement: https://codeforces.com/contest/1472/problem/B/

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

int n, sum, a, b, choice;

void harry()
{
    ii(n);
    int ar[n];
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        ii(ar[i]);
        sum += ar[i];
    }

    if (sum % 2 != 0)
        no;
    else
    {
        sum = 0;
        a = 0, b = 0;
        choice = 1;
        for (int i = 0; i < n; i++)
        {
            if (ar[i] == 2 and choice)
            {
                a += 2;
                choice = 0;
            }
            else if (ar[i] == 2 and !choice)
            {
                choice = 1;
                b += 2;
            }
            //cout << i << " " << a << " " << b << endl;
        }

        for (int i = 0; i < n; i++)
        {
            if (ar[i] == 1 and a == b)
                a += 1;
            else if (ar[i] == 1 and b > a)
                a += 1;
            else if (ar[i] == 1 and a > b)
                b += 1;
            //cout << i << " " << a << " " << b << endl;
        }
        a == b ? yes : no;
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
