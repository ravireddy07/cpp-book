// Problem Statement: https://codeforces.com/contest/1459/problem/B

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
        if (n % 2)
            printf("%d\n", 2 * (n / 2 + 2) * (n / 2 + 1));
        else
            printf("%d\n", (n / 2 + 1) * (n / 2 + 1));
        sheldon_harry;
        return;
    }
};

int main()
{
    cp a;
    a.test();
    return 0;
}

/*
Author: Ravi Kanth Gojur
Github: ravireddy07
*/
