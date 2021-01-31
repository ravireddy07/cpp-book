// Problem Statement: https://www.codechef.com/RTCG2020/problems/RTCG003

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
        string a, b;
        cin >> a >> b;
        int ans = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                ans++;
        printf("%d", ans);
        sheldon_harry;
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
