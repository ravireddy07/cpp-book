// Problem Statement: https://www.codechef.com/MAY21B/problems/KKLING

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
    int N;
    cin >> N;
    vector<vi> G(N + 1);
    vi p(N + 1), ls, C(N + 1, -1), r(N + 1), s(N + 1, 1);
    vector<bool> seen(N + 1, false);
    for (int i = 1; i < N; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    function<int(int)> find;
    function<void(int, int)> init, merge;
    function<bool(int, int)> magic;
    find = [&](int i)
    {
        if (r[i] == i)
            return i;
        return r[i] = find(r[i]);
    };
    merge = [&](int i, int j)
    {
        i = find(i);
        j = find(j);
        if (i == j)
            return;
        if (s[i] < s[j])
            swap(i, j);
        r[j] = i;
        s[i] += s[j];
    };
    init = [&](int i, int i0)
    {
        p[i] = i0;
        r[i] = i;
        if (i != 1 && G[i].size() == 1u)
        {
            ls.push_back(i);
            C[i] = i;
        }
        for (int j : G[i])
            if (j != i0)
                init(j, i);
    };
    magic = [&](int i, int j)
    {
        int c = C[j];
        C[j] = -1;
        bool leaf = true;
        for (int k : G[j])
            if (k != p[j] && !seen[k])
            {
                leaf = false;
                seen[k] = true;
                magic(i, k);
            }
        if (!leaf)
            return false;
        if (C[i] == -1)
            C[i] = c;
        else
            merge(C[i], c);
        return true;
    };
    init(1, 0);
    int t = 0;
    bool king = true;
    while (king)
    {
        ++t;
        vi ls2, leaves;
        for (int i : ls)
            if (!seen[i])
            {
                if (magic(i, i))
                    leaves.push_back(i);
                else
                    ls2.push_back(i);
            }
        for (int i : leaves)
            if (!seen[i])
            {
                seen[i] = true;
                int j = p[i];
                if (C[j] == -1)
                {
                    ls2.push_back(j);
                    C[j] = C[i];
                    if (j == 1)
                        king = false;
                }
                else
                    merge(C[j], C[i]);
            }
        ls = move(ls2);
    }
    int c = find(C[1]);
    vi a;
    for (int i = 1; i <= N; ++i)
        if (find(i) == c)
            a.push_back(i);
    cout << a.size() << ' ' << t << '\n';
    for (int i : a)
        cout << i << ' ';
    cout << '\n';
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
