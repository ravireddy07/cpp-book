// Problem Statement: https://www.codechef.com/MARCH21B/problems/LCKDSAFE

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 10;
const ll inf_ll = 1e18 + 10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template <typename it, typename cmp>
struct sparse_table
{

    using T = typename remove_reference<decltype(*declval<it>())>::type;
    vector<vector<T>> t;
    cmp f;

    sparse_table(it first, it last, cmp op) : t(1), f(op)
    {
        int n = distance(first, last);
        t.assign(32 - __builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < t.size(); i++)
            for (int j = 0; j < n - (1 << i) + 1; j++)
                t[i][j] = f(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
    }

    // returns f(a[l..r]) in O(1) time
    T query(int l, int r)
    {
        int h = floor(log2(r - l + 1));
        return f(t[h][l], t[h][r - (1 << h) + 1]);
    }
};

const int N = 1e6 + 5, K = 60;
ll a[N], v[N];

// how many in [l, r] are >= x
int geq(int l, int r, ll x)
{
    if (v[l] < x)
        return 0;
    int i = l;
    for (int k = 1 << 25; k > 0; k /= 2)
        if (i + k <= r && v[i + k] >= x)
            i += k;
    return i - l + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        fill(v, v + n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll ans = 0, pos = 0;
        vector<int> p = {-1};
        for (int i = 0; i < n; i++)
        {

            while (p.size() > 1 && a[i] >= a[p.back()])
            {
                pos -= geq(p[p.size() - 2] + 1, p.back(), a[p.back()]);
                p.pop_back();
            }
            p.pb(i);
            pos += geq(p[p.size() - 2] + 1, p.back(), a[p.back()]);

            if (i > 0)
                for (ll j = 0; j < K; j++)
                    if ((a[i] ^ a[i - 1]) & (1ll << j))
                    {
                        int k = i - 1;
                        ll mq = a[i];
                        while (k >= 0 && !(v[k] & (1ll << j)))
                        {
                            cmax(mq, a[k]);
                            if (v[k] >= mq)
                                pos--;
                            v[k] |= 1ll << j;
                            if (v[k] >= mq)
                                pos++;
                            k--;
                        }
                    }

            ans += pos;
        }

        cout << ans << "\n";
    }
}
