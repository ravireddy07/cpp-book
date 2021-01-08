// Problem Statement: https://www.codechef.com/JAN21B/problems/ORAND/

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
#define Pii pair<int, int>
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

ll t, n, m, x;
set<ll> V;
stack<ll> tempStore;
vector<ll> a, b;
void harry()
{
    V.clear();
    a.clear();
    b.clear();
    tempStore.empty();

    V.insert(0);
    tempStore.push(0);

    ill2(n, m);
    for (ll i = 0; i < n; ++i)
        ill(x), a.pb(x);
    for (ll i = 0; i < m; ++i)
        ill(x), b.pb(x);

    while (!tempStore.empty())
    {
        x = tempStore.top();
        tempStore.pop();
        for (ll i = 0; i < n; ++i)
        {
            if (!V.count(x | a[i]))
            {
                V.insert(x | a[i]);
                tempStore.push(x | a[i]);
            }
        }
        for (ll i = 0; i < m; ++i)
        {
            if (!V.count(x & b[i]))
            {
                V.insert(x & b[i]);
                tempStore.push(x & b[i]);
            }
        }
    }
    printf("%lu\n", V.size());
    //cout << V.size() << "\n";
    ravireddy07;
}

int main()
{
    ill(t);
    while (t--)
        harry();
    return 0;
}
