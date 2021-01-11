// Problem Statement: https://www.codechef.com/JAN21B/problems/ORAND/

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
#define ii2(a, b) scanf("%d%d", &a, &b)
#define ill(a) scanf("%lld", &a)
#define ill2(a, b) scanf("%lld%lld", &a, &b)
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define Pii pair<int, int>
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define pqi priority_queue<int>
#define pq priority_queue
#define yes printf("YES\n")
#define no printf("NO\n")
using namespace std;

template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}

/*
ll t, n, m, x;
set<ll> V;
stack<ll> tempStore;
vector<ll> a, b;
void harry()
{
    V.clear();
    a.clear();
    b.clear();
    tempStore.empty();

    V.insert(0);
    tempStore.push(0);

    ill2(n, m);
    for (ll i = 0; i < n; ++i)
        ill(x), a.pb(x);
    for (ll i = 0; i < m; ++i)
        ill(x), b.pb(x);

    while (!tempStore.empty())
    {
        x = tempStore.top();
        tempStore.pop();
        for (ll i = 0; i < n; ++i)
        {
            if (!V.count(x | a[i]))
            {
                V.insert(x | a[i]);
                tempStore.push(x | a[i]);
            }
        }
        for (ll i = 0; i < m; ++i)
        {
            if (!V.count(x & b[i]))
            {
                V.insert(x & b[i]);
                tempStore.push(x & b[i]);
            }
        }
    }
    printf("%lu\n", V.size());
    //cout << V.size() << "\n";
    ravireddy07;
}
*/

const int MOD = 1e9 + 7;

auto and_fw = [](int &u, int &v) {
    v = u + v;
    u = v - u;
    if (v >= MOD)
        v -= MOD;
};
auto and_inv = [](int &u, int &v) {
    u = v - u;
    v = -(u - v);
    if (u < 0)
        u += MOD;
};
auto or_fw = [](int &u, int &v) {
    u = u + v;
    v = u - v;
    if (u >= MOD)
        u -= MOD;
};
auto or_inv = [](int &u, int &v) {
    v = u - v;
    u = u - v;
    if (v < 0)
        v += MOD;
};
auto or_inv_and_fw = [](int &u, int &v) {
    u = u - v;
    v = u + v;
    if (u < 0)
        u += MOD;
};

void fwht(vector<int> &a, auto &f)
{
    int n = a.size();
    for (int m = 1; m < n; m *= 2)
        for (int i = 0; i < n; i += m * 2)
            for (int j = 0; j < m; ++j)
                f(a[i + j], a[i + j + m]);
}

vector<int> distribution_count(vector<int> a, int n)
{
    vector<int> res(n);
    for (int x : a)
        res[x] = true;
    return res;
}

inline int mul(int a, int b) { return 1LL * a * b % MOD; }
int powmod(int base, int expo)
{
    int t = 1;
    for (; expo > 0; expo >>= 1)
    {
        if (expo & 1)
            t = mul(t, base);
        base = mul(base, base);
    }
    return t;
}

void trans(vector<int> &v, const vector<int> &a, const vector<int> &b)
{
    int n = v.size();
    fwht(v, or_fw);
    transform(v.begin(), v.end(), a.begin(), v.begin(), mul);
    //    fwht(v, or_inv);
    //    for (int i = 0; i < n; ++i)
    //        v[i] = (v[i] > 0);
    //    fwht(v, and_fw);
    fwht(v, or_inv_and_fw);
    transform(v.begin(), v.end(), b.begin(), v.begin(), mul);
    fwht(v, and_inv);
    for (int i = 0; i < n; ++i)
        v[i] = (v[i] > 0);
}

int harry(vector<int> a, vector<int> b)
{
    int mx = max(*max_element(a.begin(), a.end()), *max_element(b.begin(), b.end()));
    int n = 1;
    while (n <= mx)
        n *= 2;
    a = distribution_count(a, n);
    b = distribution_count(b, n);

    a[0] = true;
    b[n - 1] = true;

    fwht(a, or_fw);
    transform(a.begin(), a.end(), a.begin(), [n](int x) { return powmod(x, n); });
    //    fwht(a, or_inv);
    //    for (int i = 0; i < 1 << 20; ++i)
    //        a[i] = (a[i] > 0);
    //    fwht(a, or_fw);

    fwht(b, and_fw);
    transform(b.begin(), b.end(), b.begin(), [n](int x) { return powmod(x, n); });
    //    fwht(b, and_inv);
    //    for (int i = 0; i < 1 << 20; ++i)
    //        b[i] = (b[i] > 0);
    //    fwht(b, and_fw);

    vector<int> c(n);
    c[0] = 1;
    int cnt = 0;
    for (;; ++cnt)
    {
        vector<int> tmp = c;
        //        cerr << cnt << "-th time\n";
        trans(c, a, b);
        if (tmp == c)
        {
            //            cerr << "Stable after " << cnt << " times.\n";
            break;
        }
    }
    return n - count(c.begin(), c.end(), 0);
}

int main()
{
    ll t;
    ill(t);
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;
        cout << harry(a, b) << "\n";
    }
    return 0;
}
