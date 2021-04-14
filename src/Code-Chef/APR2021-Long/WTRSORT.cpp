// Problem Statement: https://www.codechef.com/APRIL21B/problems/WTRSORT

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define po pop_back
#define mp make_pair
#define fi first
#define se second
#define LLM LONG_LONG_MAX
#define LLm LONG_LONG_MIN
#define MOD 1000000007
using namespace std;

bool comp(ll a, ll b)
{
    if (a > b)
        return true;
    else
        return false;
}

int isP(ll n)
{
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll t = power(a, b / 2);
    if (b % 2 == 1)
        return t * t * a;
    else
        return t * t;
}

ll powMOD(ll x, ll y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    ll t = powMOD(x, y / 2);
    if (y % 2 == 1)
        return t * t % MOD * x % MOD;
    else
        return t * t % MOD;
}

int main()
{
    ll t;
    t = 1;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll cp[n + 1];
        for (ll i = 1; i <= n + 2; i++)
            cin >> cp[i];
        ll dp[n + 1][n + 1];
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++)
                cin >> dp[i][j];
        stack<ll> bp[n + 3], bpp[n + 3];
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                ll k;
                cin >> k;
                bp[i].push(k);
                bpp[i].push(k);
            }
        }
        ll hp[n + 3], hpp[n + 3] = {};
        for (ll i = 1; i <= n + 2; i++)
            hp[i] = m, hpp[i] = m;
        vector<pair<ll, ll>> ans1;
        ll ans = 0;
        ll done[n + 1] = {}, donee[n + 1] = {};
        for (ll i = 1; i <= n; i++)
        {
            if (!bpp[i].empty())
            {
                if (!donee[bpp[i].top()])
                {
                    donee[bpp[i].top()] = i;
                    for (ll j = i + 1; j <= n; j++)
                    {
                        while (!bpp[j].empty() && donee[bpp[j].top()])
                        {
                            if (bpp[donee[bpp[j].top()]].size() == hpp[donee[bpp[j].top()]])
                            {
                                ans1.pb({0, donee[bpp[j].top()]});
                                hpp[donee[bpp[j].top()]]++;
                            }
                            ans1.pb({j, donee[bpp[j].top()]});
                            bpp[donee[bpp[j].top()]].push(bpp[j].top());
                            bpp[j].pop();
                        }
                    }
                }
            }
        }

        ll mx = 0, idxx = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (bpp[i].size() > m)
            {
                ans += (bpp[i].size() - m) * cp[i];
                if ((bpp[i].size() - m) * cp[i] > mx)
                {
                    mx = (bpp[i].size() - m) * cp[i];
                    idxx = i;
                }
            }
        }

        ans1.clear();
        for (ll i = 1; i <= n; i++)
        {
            if (!bp[i].empty())
            {
                if (!done[bp[i].top()])
                {
                    done[bp[i].top()] = i;
                    for (ll j = i + 1; j <= n; j++)
                    {
                        while (!bp[j].empty() && done[bp[j].top()])
                        {
                            if (bp[done[bp[j].top()]].size() == hp[done[bp[j].top()]])
                            {
                                if (done[bp[j].top()] == idxx)
                                {
                                    if (bp[n + 2].size() == hp[n + 2])
                                    {
                                        ans1.pb({0, n + 2});
                                        hp[n + 2]++;
                                    }
                                    ans1.pb({j, n + 2});
                                    bp[n + 2].push(bp[j].top());
                                    bp[j].pop();
                                }
                                else
                                {
                                    ans1.pb({0, done[bp[j].top()]});
                                    hp[done[bp[j].top()]]++;
                                    ans1.pb({j, done[bp[j].top()]});
                                    bp[done[bp[j].top()]].push(bp[j].top());
                                    bp[j].pop();
                                }
                            }
                            else
                            {
                                ans1.pb({j, done[bp[j].top()]});
                                bp[done[bp[j].top()]].push(bp[j].top());
                                bp[j].pop();
                            }
                        }
                    }
                }
            }
        }

        for (ll i = 1; i <= n; i++)
        {
            if (!bp[i].empty())
            {
                ll val = bp[i].top();
                while (!bp[i].empty())
                {
                    if (bp[i].top() == val)
                    {
                        ans1.pb({i, n + 1});
                        bp[n + 1].push(val);
                    }
                    else
                    {
                        if (done[bp[i].top()])
                        {
                            if (bp[done[bp[i].top()]].size() == hp[done[bp[i].top()]])
                            {
                                ans1.pb({0, done[bp[i].top()]});
                                hp[done[bp[i].top()]]++;
                            }
                            ans1.pb({i, done[bp[i].top()]});
                            bp[done[bp[i].top()]].push(bp[i].top());
                        }
                        else
                        {
                            ll idx = 0;
                            for (ll j = 1; j <= n; j++)
                            {
                                if (j != i && bp[j].empty())
                                {
                                    idx = j;
                                    break;
                                }
                            }
                            done[bp[i].top()] = idx;
                            ans1.pb({i, idx});
                            bp[idx].push(bp[i].top());
                        }
                    }
                    bp[i].pop();
                }
                while (!bp[n + 1].empty())
                {
                    ans1.pb({n + 1, i});
                    bp[i].push(bp[n + 1].top());
                    bp[n + 1].pop();
                }
            }
        }

        if (!bp[n + 2].empty())
        {
            if (bp[n + 2].size() != m)
            {
                while (!bp[n + 2].empty())
                {
                    ans1.pb({n + 2, done[bp[n + 2].top()]});
                    bp[done[bp[n + 2].top()]].push(bp[n + 2].top());
                    bp[n + 2].pop();
                }
            }
        }

        cout << "0 " << ans1.size() << "\n";
        for (ll i = 0; i < ans1.size(); i++)
        {
            if (ans1[i].fi == 0)
            {
                cout << "2 " << ans1[i].se << "\n";
            }
            else
            {
                cout << "1 " << ans1[i].fi << " " << ans1[i].se << "\n";
            }
        }
    }

    return 0;
}
