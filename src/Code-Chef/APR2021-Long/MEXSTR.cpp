// Problem Statement: https://www.codechef.com/APRIL21B/problems/MEXSTR

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
#define ii3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ill(a) scanf("%lld", &a)
#define ill2(a, b) scanf("%lld%lld", &a, &b)
#define ill3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define for1(i, a, b) for (int i = a; i < b; ++i)
#define for2(i, a, b) for (int i = b; i >= a; --i)
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define unmp unordered_map
#define pq priority_queue
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define yes printf("YES\n")
#define no printf("NO\n")
using namespace std;
ll MOD = 998244353;
#define MEX (int)1e6
int dp1[MEX + 2], dp2[MEX + 2];
int ar1[MEX], ar2[MEX];

template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}

template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (a > b)
        a = b;
    return a;
}

/*
vector<int> getPermutation(size_t n)
{
	vector<int> res;
	string s = to_string(n);
	sort(s.begin(), s.end());
	do
	{
		res.pb(stoi(s));
		//cout << s << "\n";
	} while (getPermutation(s.begin(), s.end()));
	return res;
}*/

ll fpow(ll base, ll power)
{
    ll result = 1;
    while (power > 0)
    {

        if (power & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        //power >> = 1;
        power = power / 2;
    }
    ravireddy07 result;
}

void dfs(ll s, vector<vector<ll>> &adj, vector<bool> &vis, vector<ll> &arr)
{
    if (vis[s])
        return;
    vis[s] = true;
    arr.pb(s);
    for (auto x : adj[s])
        if (vis[x] == false)
            dfs(x, adj, vis, arr);
    ravireddy07;
}

void bfs(ll x, vector<bool> &vis, vector<vector<ll>> &adlist, vector<ll> &level, vector<ll> &parent)
{
    queue<ll> q;
    vis[x] = true;
    q.push(x);
    while (!q.empty())
    {
        ll s = q.front();
        q.pop();
        // process node s
        for (auto u : adlist[s])
        {
            if (vis[u])
                continue;
            vis[u] = true;
            parent[u] = s;
            level[u] = level[s] + 1;
            q.push(u);
        }
    }
    ravireddy07;
}

void harry()
{
    string s;
    cin >> s;
    int n = s.size();
    string res = "1";

    int cnt = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            for (int j = cnt + 1; j <= i; j++)
            {
                ar1[j] = i;
            }
            cnt = i;
        }
    }

    for (int i = cnt + 1; i < s.size(); i++)
        ar1[i] = n;

    cnt = -1;

    if (ar1[0] == n)
    {
        printf("0\n");
        ravireddy07;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            for (int j = cnt + 1; j <= i; j++)
            {
                ar2[j] = i;
            }
            cnt = i;
        }
    }

    dp1[n] = dp1[n + 1] = 0;
    dp2[n] = dp2[n + 1] = 0;

    for (int i = cnt + 1; i < s.size(); i++)
        ar2[i] = n;

    for (int i = n - 1; i >= 0; i--)
    {
        dp1[i] = dp1[i + 1];
        if (s[i] == '1' and ar1[i] < n)
            dp1[i] = amax(dp1[i], dp1[ar1[i] + 1] + 1);
        if (s[i] == '0' and ar2[i] < n)
            dp1[i] = amax(dp1[i], dp1[ar2[i] + 1] + 1);
        dp2[i] = dp2[i + 1];
        if (ar2[i] < n)
            dp2[i] = amax(dp2[i], dp1[ar2[i] + 1] + 1);
    }

    int nn = dp2[0] + 1, temp = ar2[0] + 1;
    for (int i = 1; i < nn; i++)
    {
        if (temp >= n)
            res += '0';
        else if (ar1[temp] >= n)
        {
            res += '0';
            temp = ar1[temp] + 1;
        }
        else if (dp1[ar1[temp] + 1] < nn - i - 1)
        {
            res += '0';
            temp = ar1[temp] + 1;
        }
        else
        {
            res += '1';
            temp = ar2[temp] + 1;
        }
    }

    cout << res << "\n";
    ravireddy07;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    ii(t);
    while (t--)
        harry();
    return 0;
}
