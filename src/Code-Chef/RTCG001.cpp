// Problem Statement: https://www.codechef.com/PBK32020/problems/RTCG001

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
        ll n;
        ill(n);
        string s;
        s = to_string(n);
        ll res = 0;
        ll temp = 0;
        for (int i = 0; i < s.size(); i++)
        {
            temp = (ll)s[i] - 48;
            if (temp == 0)
                continue;
            else if (n % temp == 0)
                res++;
        }
        cout << res;
        sheldon_harry;
        return;
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
