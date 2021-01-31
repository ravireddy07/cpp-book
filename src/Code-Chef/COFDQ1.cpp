// Problem Statement: https://www.codechef.com/COFDEC20/problems/COFDQ1

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
        int n, k;
        cin >> n;
        int v[n];
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cin >> k;

        vector<int> tmp;
        for (int i = 0; i < n - k + 1; i++)
        {
            tmp.clear();
            for (int j = i; j < i + k; j++)
                tmp.push_back(v[j]);
            sort(tmp.begin(), tmp.end());
            if (k % 2 == 1)
                cout << tmp[k / 2] << " ";
            else
            {
                double ans = ((tmp[k / 2] + tmp[k / 2 - 1]) / 2.0);
                cout << fixed << setprecision(1) << ans << " ";
            }
        }

        sheldon_harry;
        return;
    }
};

int main()
{
    cp a;
    int t;
    a.test();
    return 0;
}

/*
Author: Ravi Kanth Gojur
Github: ravireddy07
*/
