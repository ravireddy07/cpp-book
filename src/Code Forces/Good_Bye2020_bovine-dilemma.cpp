// Problem Statement: https://codeforces.com/contest/1466/problem/A/

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#define ll long long int
#define ravireddy07 return
#define ii(a) scanf("%d", &a)
#define ill(a) scanf("%lld", &a)
#define pb push_back
#define sort(a) sort(a.begin(), a.end())
#define yes printf("YES")
#define no printf("NO")
using namespace std;

class moon_pie
{
public:
    double findArea(double dX0, double dY0, double dX1, double dY1, double dX2, double dY2)
    {
        double dArea = ((dX1 - dX0) * (dY2 - dY0) - (dX2 - dX0) * (dY1 - dY0)) / 2.0;
        return (dArea > 0.0) ? dArea : -dArea;
    }
    // Solution #1
    void harry()
    {
        int n;
        ii(n);
        int ar[n];
        for (int i = 0; i < n; ++i)
            ii(ar[i]);
        set<double> res;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                res.insert(findArea(0, 1, ar[i], 0, ar[j], 0));

        cout << res.size() << endl;
        return;
    }

    // Solution #2
    void harry()
    {
        int n;
        ii(n);
        vector<int> x(n);
        for (int i = 0; i < n; i++)
            ii(x[i]);

        set<int> s;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                s.insert(x[j] - x[i]);

        cout << s.size() << '\n';
        ravireddy07;
    }
};

int main()
{
    moon_pie shelly;
    int t;
    scanf("%d", &t);
    while (t--)
        shelly.harry();
    return 0;
}
