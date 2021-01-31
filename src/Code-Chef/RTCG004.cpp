// Problem Statement: https://www.codechef.com/RTCG2020/problems/RTCG004

#include <bits/stdc++.h>
#define ll long long int
#define sheldon_harry printf("\n")
#define ii(a) scanf("%d", &a)
#define ill(a) scanf("%lld", &a)
#define f (i, x, y) for (int i = x; i < y; ++i)
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define yes printf("YES")
#define no printf("NO")
using namespace std;

class cp
{
public:
    void test()
    {
        string a;
        cin >> a;
        ll ans = 0;
        ll i = (a.size() % 2 == 0) ? a.size() / 2 : (a.size() / 2) + 1;
        ll j = (a.size() % 2 == 0) ? i - 1 : i - 2;
        for (i; i < a.size(); i++)
        {
            ans += abs(a[i] - a[j]);
            j--;
        }
        printf("%lld", ans);
        sheldon_harry;
    }
};

int main()
{
    cp a;
    int t;
    ii(t);
    while (t--)
        a.test();
    return 0;
}

/*
Author: Ravi Kanth Gojur
Github: ravireddy07
*/
