// Problem Statement:  https://www.codechef.com/BYTR20B/problems/CAB/

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
    ll lstbt(ll val)
    {
        ll msk = val & (val - 1);
        return log2(val ^ msk);
    }

    void harry()
    {
        ll n, k;
        scanf("%lld%lld", &n, &k);

        vl arr(32, 0);
        ll curr = k, cnt = 0;

        while (curr != 0)
        {
            cnt++;
            arr[lstbt(curr)]++;
            curr = (curr & (curr - 1));
        }

        if (n < cnt)
        {
            printf("-1");
            ravireddy07;
            return;
        }

        ll diff = n - cnt;

        for (ll i = 32 - 1; i >= 0; --i)
        {
            if (diff == 0)
                break;
            else if (i == 0)
            {
                printf("-1");
                ravireddy07;
                return;
            }
            while (arr[i] > 0 and diff > 0)
            {
                arr[i]--;
                arr[i - 1] += 2;
                diff--;
            }
        }

        for (ll i = 0; i < 32; ++i)
            for (ll j = 0; j < arr[i]; ++j)
                cout << char(i + 'a');

        ravireddy07;
        return;
    }
};
// g++ a.cpp -o a

int main()
{
    moon_pie shelly;
    int t;
    scanf("%d", &t);
    while (t--)
        shelly.harry();
    return 0;
}
