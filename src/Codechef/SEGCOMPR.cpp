// https://www.codechef.com/OCT20B/problems/SEGCOMPR

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int hs(int n)
{
    if (n == 0)
        return 0;
    int msb = 0;
    n /= 2;
    while (n != 0)
    {
        n /= 2;
        msb++;
    }
    return (1 << msb);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < v.size(); i++)
            cin >> v[i];
        ll res = 0, j = 0, i = 0;

        while (v.size() > 1)
        {
            if (v[0] != v[1])
            {
                j = max(v[0], v[1]);
                res += hs(j);
                v.push_back(res);
                v.erase(v.begin(), v.begin() + 2);
            }
            else
            {
                v.push_back(0);
                v.erase(v.begin(), v.begin() + 2);
            }
        }
        cout << endl
             << v[0] << endl;
    }
    return 0;
}