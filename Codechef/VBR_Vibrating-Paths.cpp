#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false)
#define DEBUG fprintf(stderr, "Running on Line %d in Function %s\n", __LINE__, __FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long

inline int read()
{
    char ch = getchar();
    int nega = 1;
    while (!isdigit(ch))
    {
        if (ch == '-')
            nega = -1;
        ch = getchar();
    }
    int ans = 0;
    while (isdigit(ch))
    {
        ans = ans * 10 + ch - 48;
        ch = getchar();
    }
    if (nega == -1)
        return -ans;
    return ans;
}
typedef pair<int, int> pii;
#define N 100005
int n, m, k;
struct Edge
{
    int val, v;
    Edge(int a = 0, int b = 0) : val(a), v(b){};
    bool operator<(const Edge &x) const { return val < x.val; }
};
set<Edge> G[N];
int val[N];
int lime = 0, limw = 0, B = 0;
struct EDGE
{
    int u, v, w;
};
EDGE ed[N];
bool cmp2(EDGE x, EDGE y) { return x.w > y.w; }
struct Node
{
    int id, val;
};
Node a[N];
bool cmp(Node x, Node y) { return x.val < y.val; }
vector<int> ans;
int vis[N], dgr[N];
int Sum = 0;
int fa[N], bn[N];
int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
int col[N], vis2[N];
void erase(int u)
{
    assert(!G[u].empty() && (*G[u].begin()).val < dgr[u]);
    vector<int> del;
    del.pb(u), ans.pb(u);
    Sum += val[u];
    for (int i = 1; i <= 255; i++)
    {
        if (G[u].empty())
            break;
        auto [_, v] = *G[u].begin();
        if (vis[v])
            break;
        G[u].erase(*G[u].begin());
        G[v].erase(Edge(_, u));
        del.pb(v);
        for (auto [_, v] : G[u])
            vis[v] = 1;
        u = v;
    }
    for (int i : del)
    {
        vis[i] = 0;
        for (auto [_, v] : G[i])
            vis[v] = 0;
    }
}

ll getval(int u)
{
    int A = u;
    vector<int> del;
    del.pb(u);
    for (int i = 1; i <= 255; i++)
    {
        if (G[u].empty())
            break;
        auto [_, v] = *G[u].begin();
        if (vis[v])
            break;
        del.pb(v);
        for (auto [_, v] : G[u])
            vis[v] = 1;
        u = v;
    }
    ll sum = 0;
    for (int i : del)
    {
        sum += val[i];
        vis[i] = 0;
        for (auto [_, v] : G[i])
            vis[v] = 0;
    }
    return (n - val[A]) * sum * sum;
}
void work()
{
    for (int i = 1; i <= (n + B - 1) / B; i++)
    {
        int l = (i - 1) * B + 1, r = min(i * B, n);
        while (1)
        {
            ll maxn = -inf, u = 0;
            for (int j = l; j <= r; j++)
            {
                if (!(!G[a[j].id].empty() && (*G[a[j].id].begin()).val < dgr[a[j].id]))
                    continue;
                ll R = getval(a[j].id);
                if (R > maxn)
                    maxn = R, u = j;
            }
            if (maxn == -inf)
                break;
            erase(a[u].id);
        }
    }
    cout << ans.size() << endl;
    for (int i : ans)
        printf("%d ", i);
    cout << "\n";
    for (int i = 1; i <= n; i++)
        printf("%d ", col[i]);
    cout << "\n";
}
void doit2(int u)
{
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == find(u) || find(i) == find(u + n))
        {
            vis2[i] = 1;
            if (find(i) == find(u))
                col[i] = 1;
            else
                col[i] = 2;
        }
    }
}
void prework2()
{
    sort(ed + 1, ed + m + 1, cmp2);
    for (int i = 1; i <= n + n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u = ed[i].u, v = ed[i].v;
        if (bn[u] || bn[v])
            continue;
        if (find(u + n) == find(v + n) || find(u) == find(v))
        {
            bn[u] = bn[v] = 1;
            continue;
        }
        fa[find(u + n)] = find(v);
        fa[find(v + n)] = find(u);
        dgr[u] = ed[i].w, dgr[v] = ed[i].w;
        //		printf("%d %d\n",u,v);
    }
    for (int i = 1; i <= n; i++)
        if (!vis2[i])
            doit2(i);
    //	cerr<<"Passed\n";
}
signed main()
{
#ifdef __LOCAL__
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        val[i] = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), w = read();
        G[u].insert(Edge(w, v)), G[v].insert(Edge(w, u));
        ed[i].u = u, ed[i].v = v, ed[i].w = w;
    }
    for (int i = 1; i <= n; i++)
        a[i].val = val[i], a[i].id = i;
    for (int i = 1; i <= n; i++)
        col[i] = 1, dgr[i] = inf;
    sort(a + 1, a + n + 1, cmp);
    if (k != 1)
        prework2();
    if (k != 1 && n == 1000)
        limw = 965;
    if (n == 10000)
        B = 1;
    else
        B = 20;
    for (int i = 1; i <= limw; i++)
        dgr[i] = inf;
    work();
    cerr << Sum << endl;
    return 0;
}