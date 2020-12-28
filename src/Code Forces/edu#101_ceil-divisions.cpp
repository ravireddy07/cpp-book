// Problem Statement: https://www.codeforces.com/contest/1469/problem/D/

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
        int cnt = 0;
        if (n <= 12)
        {
            cout << n + 1 << endl;
            for (int i = n - 1; i > 2; i--)
            {
                cnt++;
                cout << i << " " << n << endl;
            }
            for (int i = 0; i < 4; i++)
            {
                cnt++;
                cout << n << " " << 2 << endl;
            }
            // cout<<cnt<<endl;
            return;
        }
        cout << n + 5 << endl;
        for (int i = n - 1; i > 2; i--)
        {
            if (i == 12)
                continue;
            cnt++;
            cout << i << " " << n << endl;
        }
        for (int i = 0; i < 5; i++)
        {
            cnt++;
            cout << n << " " << 12 << endl;
        }
        for (int i = 0; i < 4; i++)
        {
            cnt++;
            cout << 12 << " " << 2 << endl;
        }
        ravireddy07;
        return;
    }
};
// g++ d.cpp -o d

int main()
{
    moon_pie shelly;
    int t;
    ii(t);
    while (t--)
        shelly.harry();
    return 0;
}
