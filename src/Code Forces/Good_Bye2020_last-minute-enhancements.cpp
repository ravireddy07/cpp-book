// Problem Statement: https://codeforces.com/contest/1466/problem/B/

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
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

class moon_pie
{
public:
    void harry()
    {
        int n;
        scanf("%d", &n);
        ll ar[n];
        for (int i = 0; i < n; ++i)
            ill(ar[i]);
        map<int, int> m;
        for (int i : ar)
        {
            if (m[i] == 0)
                m[i]++;
            else
                m[i + 1]++;
        }
        cout << m.size() << endl;
        ravireddy07;
        return;
    }
};

int main()
{
    moon_pie shelly;
    int t;
    scanf("%d", &t);
    while (t--)
        shelly.harry();
    return 0;
}
