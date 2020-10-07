// https://www.codechef.com/OCT20B/problems/SEGCOMPR

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int hs(int num)
{
    if (!num)
        return 0;
    int ret = 1;
    while (num >>= 1)
        ret <<= 1;
    return ret;
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
        ll res = 0;

        while (v.size() > 1)
        {
            if (v[0] != v[1])
            {
                res = hs(v[0]) + hs(v[1]);
                v.erase(v.begin(), v.begin() + 2);
                v.push_back(res);
            }
            else
            {
                v.erase(v.begin(), v.begin() + 2);
                v.push_back(0);
            }
        }
        cout << endl
             << (v[0] * n) << endl;
    }
    return 0;
}