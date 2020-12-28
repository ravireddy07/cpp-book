// Problem Statement: https://www.codeforces.com/contest/1469/problem/B/

/**
 *  Author: Ravi Kanth Gojur
 *  Handle: ravireddy07
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#define ll long long int
#define ravireddy07 printf("\n")
#define ii(a) scanf("%d", &a)
#define ill(a) scanf("%lld", &a)
#define pb push_back
#define sort(a) sort(a.begin(), a.end())
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define yes printf("YES")
#define no printf("NO")
using namespace std;

template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}

class moon_pie
{
public:
    void harry()
    {
        int n;
        ii(n);
        int sum = 0, res = 0, temp = 0;

        int r[n];
        for (int i = 0; i < n; i++)
        {
            ii(r[i]);
            sum += r[i];
            amax(res, sum);
        }

        int m;
        ii(m);

        int b[m];
        sum = 0;
        for (int i = 0; i < m; i++)
        {
            ii(b[i]);
            sum += b[i];
            amax(temp, sum);
        }

        res = res + temp;
        cout << res;
        ravireddy07;
        return;
    }
};
// g++ b.cpp -o b

int main()
{
    moon_pie shelly;
    int t;
    ii(t);
    while (t--)
        shelly.harry();
    return 0;
}
