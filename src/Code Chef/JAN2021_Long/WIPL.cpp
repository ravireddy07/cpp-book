// Problem Statement: https://www.codechef.com/JAN21B/problems/WIPL/

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
#define yes printf("YES")
#define no printf("NO")
using namespace std;

int dp[4017][4017];
int posi[4017];
int n, k, ans;

/*
void harry1()
{
    ii2(n, k);
    int heightList[n];
    for (int i = 0; i < n; ++i)
        ii(heightList[i]);
    sort(heightList, heightList + n, greater<int>());
    vi set1, set2;
    int set1Sum = 0, set2Sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((i & 1) and set1Sum < k)
        {
            set1Sum += heightList[i];
            set1.pb(heightList[i]);
        }
        else if (set2Sum < k)
        {
            set2Sum += heightList[i];
            set2.pb(heightList[i]);
        }
    }
    cout << set1.size() + set2.size() << endl;
    ravireddy07;
    // 1 10 40 14 3 7 8 9 7 12 15 10 6
    // 8
}*/

/*
8 38 7 8 19 7 8 7 10 20
7

4 5 2 10 4 9
2

8 10 9 8 4 3 1 1 1 1
4

8 10 9 8 7 1 1 1 1 1
5(4)

10 40 14 3 7 8 9 7 12 15 10 6
9(8)

*/

int tryBox(int index, int notVaild, vi &heightList)
{
    if (notVaild >= k and (posi[index] - notVaild >= k))
        return 0;
    else if (index >= n)
        return 1e5;
    else if (dp[index][notVaild] != -1)
        return dp[index][notVaild];
    else
        return dp[index][notVaild] = 1 + min(tryBox(index + 1, min(notVaild + heightList[index], posi[index] - notVaild), heightList), tryBox(index + 1, min(posi[index] - notVaild + heightList[index], notVaild), heightList));
}

void harry()
{
    ii2(n, k);
    vi heightList(n, 0);
    for (int i = 0; i < n; ++i)
        ii(heightList[i]);
    sorta(heightList);

    if (n & 1 || n > 1)
    {
        for (int i = 0; i < n / 2; ++i)
            swap(heightList[i], heightList[n - i - 1]);

        for (int i = 0; i <= n + 10; ++i)
        {
            posi[i] = 0;
            for (int j = 0; j <= k + 10; ++j)
                dp[i][j] = -1;
        }

        for (int i = 1; i <= n; ++i)
            posi[i] = posi[i - 1] + heightList[i - 1];

        ans = tryBox(0, 0, heightList);
        printf("%d\n", (ans > 1e5 ? -1 : ans));
    }
    else
        printf("-1\n");
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
