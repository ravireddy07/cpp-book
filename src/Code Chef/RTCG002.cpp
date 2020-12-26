// Problem Statement: https://www.codechef.com/RTCG2020/problems/RTCG002

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
        string s;
        cin >> s;
        int total = 0;
        for (auto i : s)
        {
            if (i == 'D')
                total += 238;
            else if (i == 'T')
                total += 244;
            else if (i == 'M')
                total += 138;
            else if (i == 'B')
                total += 279;
            else if (i == 'C')
                total += 186;
        }
        int r = 0, c = 0, w = 0;
        r = total / 50;
        total -= r * 50;
        c = total / 5;
        total -= c * 5;
        w = total / 0.5;
        cout << r << endl;
        cout << c << endl;
        cout << w << endl;
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
