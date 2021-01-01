// Problem Statement: https://www.codechef.com/JAN21B/problems/FAIRELCT/

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#define ll long int
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
#define pqi priority_queue<int>
#define pq priority_queue
#define sort(a) sort(a.begin(), a.end())
#define yes printf("YES")
#define no printf("NO")
using namespace std;

int n, m, temp, minn, maxx, jackSum, johnSum;

int checkSum(int john[], int jack[])
{
    int johnSum = 0, jackSum = 0;
    for (int i = 0; i < n; i++)
        johnSum += john[i];
    for (int i = 0; i < m; i++)
        jackSum += jack[i];
    return (johnSum == jackSum ? -1 : (johnSum > jackSum ? 1 : 0));
}

void harry_TLE()
{
    ii2(n, m);
    int john[n], jack[m];
    johnSum = 0, jackSum = 0;
    for (int i = 0; i < n; ++i)
    {
        ii(john[i]);
        johnSum += john[i];
    }

    for (int i = 0; i < m; ++i)
    {
        ii(jack[i]);
        jackSum += jack[i];
    }

    if (johnSum == jackSum)
        printf("-1\n");
    else
    {
        int ans = 0;
        //int i = 0, j = m - 1;
        while (johnSum < jackSum)
        {
            minn = *min_element(john, john + n);
            maxx = *max_element(jack, jack + m);
            auto ind1 = find(john, john + n, minn);
            auto ind2 = find(jack, jack + m, maxx);
            swap(john[distance(john, ind1)], jack[distance(jack, ind2)]);
            ++ans;

            /* using vector
            swap(john[distance(john.begin(), min_element(john.begin(), john.end()))], jack[distance(jack.begin(), max_element(jack.begin(), jack.end()))]);
            ++ans;
            */

            /* sorted votes
            swap(john[i], jack[j]);
            johnSum = johnSum - jack[j] + john[i];
            jackSum = jackSum + jack[j] - john[i];
            ++ans;
            ++i;
            --j;*/
        }
        printf("%d\n", ans);
    }
    ravireddy07;
}

void harry()
{
    ii2(n, m);
    pq<int, vi, greater<int>> John;
    pqi Jack;

    for (int i = 0; i < n; ++i)
    {
        ii(temp);
        johnSum += temp;
        John.push(temp);
    }

    for (int i = 0; i < m; ++i)
    {
        ii(temp);
        jackSum += temp;
        Jack.push(temp);
    }

    if (johnSum == jackSum)
        printf("-1\n");
    else if (johnSum > jackSum)
        printf("0\n");
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            minn = John.top();
            maxx = Jack.top();
            John.pop();
            Jack.pop();
            John.push(maxx);
            Jack.push(minn);
            johnSum = johnSum - minn + maxx;
            jackSum = jackSum - maxx + minn;
            if (johnSum > jackSum)
            {
                printf("%d\n", i);
                break;
            }
        }
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
