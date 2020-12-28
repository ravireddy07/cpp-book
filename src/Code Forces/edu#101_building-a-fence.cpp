// Problem Statement: https://www.codeforces.com/contest/1469/problem/C/

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
        int n, k;
        ii(n);
        ii(k);
        int h[n];
        for (int i = 0; i < n; i++)
            ii(h[i]);

        int lo[n], hi[n];
        for (int i = 0; i < n; i++)
            lo[i] = hi[i] = -1e9;
        lo[0] = hi[0] = 0;

        for (int i = 1; i < n; i++)
        {
            lo[i] = max(0, h[i - 1] + lo[i - 1] - k + 1 - h[i]);
            hi[i] = min(k - 1, h[i - 1] + hi[i - 1] + k - 1 - h[i]);
            if (hi[i] < lo[i])
                break;
        }

        cout << (lo[n - 1] == 0 && hi[n - 1] >= lo[n - 1] ? "YES" : "NO");
        ravireddy07;
        return;
    }
};
// g++ c.cpp -o c

int main()
{
    moon_pie shelly;
    int t;
    ii(t);
    while (t--)
        shelly.harry();
    return 0;
}
