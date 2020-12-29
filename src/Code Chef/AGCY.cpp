// Problem Statement:  https://www.codechef.com/BYTR20B/problems/AGCY/

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
#define vpp vector<PP>
#define PP pair<ll, ll>
#define yes printf("YES")
#define no printf("NO")
using namespace std;

ll n, q;
ll l, r;

class moon_pie
{
public:
    // TLE Solution
    void harry()
    {
        scanf("%lld%lld", &n, &q);
        vector<int> dCities(n, 0);

        for (int i = 0; i < q; ++i)
        {
            int count = 1;
            scanf("%lld%lld", &l, &r);
            for (int j = l; j <= r; ++j)
            {
                dCities[j - 1] += count;
                count++;
            }
        }
        for (int j = 0; j < n; ++j)
            printf("%d ", dCities[j]);
        ravireddy07;
        return;
    }

    void harry()
    {
        scanf("%lld%lld", &n, &q);
        vpp arr(q);

        for (ll i = 0; i < q; ++i)
        {
            cin >> arr[i].first >> arr[i].second;
            arr[i].second++;
        }

        vl dCities(n + 1, 0), start(n + 1, 0);
        vll eachDay(n + 2);

        for (auto i : arr)
        {
            eachDay[i.second].pb(i.first);
            start[i.first]++;
        }

        ll sum = 0, cnt = 0;
        for (ll i = 1; i <= n; ++i)
        {
            cnt += start[i];
            sum += (start[i] * i);
            for (auto v : eachDay[i])
            {
                sum -= v;
                cnt--;
            }

            dCities[i] = (cnt * i - sum + cnt);
        }

        for (ll i = 0; i < n; ++i)
            printf("%lld ", dCities[i + 1]);

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
