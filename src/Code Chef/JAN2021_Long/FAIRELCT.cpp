// Problem Statement: https://www.codechef.com/JAN21B/problems/FAIRELCT/

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
#define pqi priority_queue<int>
#define pq priority_queue
#define sort(a) sort(a.begin(), a.end())
#define yes printf("YES")
#define no printf("NO")
using namespace std;

ll n, m, temp, minn, maxx, JackSum, JohnSum;

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
    JohnSum = 0, JackSum = 0;
    for (int i = 0; i < n; ++i)
    {
        ii(john[i]);
        JohnSum += john[i];
    }

    for (int i = 0; i < m; ++i)
    {
        ii(jack[i]);
        JackSum += jack[i];
    }

    if (JohnSum == JackSum)
        printf("-1\n");
    else
    {
        int ans = 0;
        //int i = 0, j = m - 1;
        while (JohnSum < JackSum)
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
            swap(John[i], Jack[j]);
            JohnSum = JohnSum - Jack[j] + John[i];
            JackSum = JackSum + Jack[j] - John[i];
            ++ans;
            ++i;
            --j;*/
        }
        printf("%d\n", ans);
    }
    ravireddy07;
}

void harry_exp()
{
    n, m;
    ill2(n, m);
    priority_queue<ll, std::vector<ll>, greater<int>> John;
    priority_queue<ll> Jack;

    JohnSum = 0, JackSum = 0, temp = 0;
    for (int i = 0; i < n; i++)
    {
        ill(temp);
        JohnSum += temp;
        John.push(temp);
    }

    for (int i = 0; i < m; i++)
    {
        ill(temp);
        JackSum += temp;
        Jack.push(temp);
    }

    if (JohnSum > JackSum)
    {
        printf("0\n");
        return;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            minn = John.top();
            maxx = Jack.top();
            John.pop();
            Jack.pop();
            John.push(maxx);
            Jack.push(minn);
            JohnSum = JohnSum - minn + maxx;
            JackSum = JackSum - maxx + minn;
            if (JohnSum > JackSum)
            {
                printf("%d\n", i + 1);
                return;
            }
        }
    }
    printf("-1\n");
    return;
}

int main()
{
    int t;
    ii(t);
    while (t--)
        harry_exp();
    return 0;
}
