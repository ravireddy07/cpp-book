// https://www.codechef.com/OCT20B/problems/SEGCOMPR

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int nax = 3e5 + 10;
const int MOD = 998244353;

// TLE Solution
/*
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
*/

void add(int &a, int b)
{
    a += b;
    while (a >= MOD)
        a -= MOD;
    while (a < 0)
        a += MOD;
}

int mx_bit(int f)
{
    if (f == 0)
        return 0;
    for (int i = 30; i >= 0; --i)
        if (f >> i & 1)
            return (1 << i);
    throw;
}

int f(int x)
{
    if (x == 0)
        return 0;
    int k = 30;
    while (x < (1 << k))
        k--;
    return (1 << k);
}

/**
    conclusion:
    If the number in MSB is odd -> answer is 1 << for sure?
    From now on let's assume that number in MSB is "even"

    If len > 3 ?
    If the number if MSB is even

    Good claim: if there is at least one "zero"
    answer will be immediately zero?

    if len > 4 we can always make it zero!!!

    So simply speaking,
    the answer for array is

    len <= 4 BF
    if number of MSB is odd -> 1 << MSB
    otherwise zeros
*/

int stupid(vector<int> p)
{
    if ((int)p.size() == 1)
        return p[0];
    int res = 1 << 30;
    for (int i = 0; i < (int)p.size(); i++)
        for (int j = i + 1; j < (int)p.size(); j++)
        {
            vector<int> q = p;
            q.erase(q.begin() + j);
            q.erase(q.begin() + i);
            q.push_back(f(p[i] ^ p[j]));
            res = min(res, stupid(q));
        }
    return res;
}

int n;
int a[nax];

int calc(const vector<int> &f, int x)
{
    static int pref[2];
    memset(pref, 0, sizeof(pref));

    int st = 0;
    int64_t all = 0;

    pref[0] = 1;
    for (int i = 0; i < int(f.size()); ++i)
    {
        int cur = st ^ (f[i] >> x & 1);
        all += pref[cur ^ 1];
        st = cur;
        pref[st] += 1;
    }

    for (int i = 0; i < int(f.size()); ++i)
    {
        int bar = 0;
        for (int j = i; j < int(f.size()) && j - i + 1 <= 4; ++j)
        {
            bar ^= f[j] >> x & 1;
            if (bar)
                all -= 1;
        }
    }

    return (all % MOD) * (1LL << x) % MOD;
}

int main()
{

    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = 0;

    vector<int> foo;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n && j - i + 1 <= 4; ++j)
        {
            foo.push_back(a[j]);
            add(ans, stupid(foo));
        }
        foo.clear();
    }

    for (int x = 29; x >= 0; --x)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] >= (1LL << (x + 1)))
            {
                add(ans, calc(foo, x));
                foo.clear();
            }
            else
            {
                foo.push_back(a[i]);
            }
        }
        add(ans, calc(foo, x));
        foo.clear();
    }

    cout << ans << '\n';
}
