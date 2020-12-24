// Problem Statement: https://codeforces.com/contest/1459/problem/A

#include <bits/stdc++.h>
#define ll long long int
#define sheldon_harry printf("\n")
#define oi(a) printf("%d\n", a)
#define oll(a) printf("%lld\n", a)
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
        int n;
        ii(n);
        string r, b;
        cin >> r >> b;
        int rr = 0;
        int bb = 0;
        for (int i = 0; i < n; i++)
        {
            if (r[i] - 48 > b[i] - 48)
                rr++;
            else if (r[i] - 48 < b[i] - 48)
                bb++;
        }

        if (rr == bb)
            printf("EQUAL");
        else if (rr > bb)
            printf("RED");
        else if (rr < bb)
            printf("BLUE");
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
