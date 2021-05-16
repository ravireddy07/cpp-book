// Problem Statement: https://www.odechef.om/MAY21B/problems/TCTCTOE

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
#define se seond
#define mp make_pair
#define unmp unordered_map
#define pq priority_queue
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define yes printf("YES\n")
#define no printf("NO\n")
#define setValue(a, value) memset(a, value, sizeof(a))
using namespace std;
ll MOD = 1e9 + 7;

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
		//out << s << "\n";
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
    char ar[3][3];
    int x = 0, o = 0, s = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> ar[i][j];
            if (ar[i][j] == 'X')
                x++;
            else if (ar[i][j] == 'O')
                o++;
            else
                s++;
        }
    }
    int cntX = 0, cntO = 0;

    if (ar[0][0] == 'X' and ar[0][1] == 'X' and ar[0][2] == 'X')
        cntX = 1;
    if (ar[0][0] == 'O' and ar[0][1] == 'O' and ar[0][2] == 'O')
        cntO = 1;
    if (ar[0][0] == 'X' and ar[1][0] == 'X' and ar[2][0] == 'X')
        cntX = 1;
    if (ar[0][0] == 'O' and ar[1][0] == 'O' and ar[2][0] == 'O')
        cntO = 1;
    if (ar[0][0] == 'X' and ar[1][1] == 'X' and ar[2][2] == 'X')
        cntX = 1;
    if (ar[0][0] == 'O' and ar[1][1] == 'O' and ar[2][2] == 'O')
        cntO = 1;
    if (ar[0][1] == 'X' and ar[1][1] == 'X' and ar[2][1] == 'X')
        cntX = 1;
    if (ar[0][1] == 'O' and ar[1][1] == 'O' and ar[2][1] == 'O')
        cntO = 1;
    if (ar[0][2] == 'X' and ar[1][2] == 'X' and ar[2][2] == 'X')
        cntX = 1;
    if (ar[0][2] == 'O' and ar[1][2] == 'O' and ar[2][2] == 'O')
        cntO = 1;
    if (ar[0][2] == 'X' and ar[1][1] == 'X' and ar[2][0] == 'X')
        cntX = 1;
    if (ar[0][2] == 'O' and ar[1][1] == 'O' and ar[2][0] == 'O')
        cntO = 1;
    if (ar[1][0] == 'X' and ar[1][1] == 'X' and ar[1][2] == 'X')
        cntX = 1;
    if (ar[1][0] == 'O' and ar[1][1] == 'O' and ar[1][2] == 'O')
        cntO = 1;
    if (ar[2][0] == 'X' and ar[2][1] == 'X' and ar[2][2] == 'X')
        cntX = 1;
    if (ar[2][0] == 'O' and ar[2][1] == 'O' and ar[2][2] == 'O')
        cntO = 1;

    if ((cntX == 1 and cntO == 1) or (x - o < 0) or (x - o > 1))
        printf("3\n");
    else if ((x == 0 and o == 0 and s == 9) or (cntX == 0 and cntO == 0 and s > 0))
        printf("2\n");
    else if ((cntX == 1 and cntO == 0 and x > o) or (cntX == 0 and cntO == 1 and x == o))
        printf("1\n");
    else if (cntX == 0 and cntO == 0 and s == 0)
        printf("1\n");
    else
        printf("3\n");
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
