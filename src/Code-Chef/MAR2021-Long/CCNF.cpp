// Problem Statement: https://www.codechef.com/MARCH21B/problems/CCNF

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fir first
#define sec second
using namespace std;

inline ll read()
{
    ll num = 0, neg = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            neg = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        num = (num << 3) + (num << 1) + c - '0';
        c = getchar();
    }
    return num * neg;
}

const int inf = 1e9;
const int N = 150, A = 513;

char str[N];
int n, m, k, c[N], bit[N], bln[N], e[N][N], pe[N], rk[N], siz[N], siz0[N];
int rt, ans, all, tot, tms, tag[N], tag0[N], anc[N], vis[N][A], f[N][A], w[N];
std::vector<int> a[N], b[N], cl[N], id[N], tr[N], has[N];

struct Edge
{
    int u, v, w;
} edg[N * N];

bool operator<(const Edge &i, const Edge &j) { return i.w > j.w; }

std::vector<int> intersect(std::vector<int> a, std::vector<int> b)
{
    std::vector<int> c;
    tms++;
    for (auto u : a)
        tag[u] = tms;
    for (auto u : b)
        if (tag[u] == tms)
            c.push_back(u);
    return c;
}

int find(int u) { return anc[u] == u ? u : anc[u] = find(anc[u]); }

void mcs()
{
    int deg[N], max = 0;
    std::vector<int> p[N];
    for (int u = 1; u <= n; u++)
    {
        deg[u] = 0;
        p[0].push_back(u);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int u = -1;
        for (;; max--)
        {
            for (; !p[max].empty(); p[max].pop_back())
            {
                if (deg[p[max].back()] != -1)
                {
                    u = p[max].back();
                    break;
                }
            }
            if (u != -1)
            {
                break;
            }
        }
        pe[i] = u;
        rk[u] = i;
        deg[u] = -1;
        for (int v = 1; v <= n; v++)
        {
            if (!e[u][v] || deg[v] == -1)
            {
                continue;
            }
            max = std::max(max, ++deg[v]);
            p[deg[v]].push_back(v);
        }
    }
}

void dfs(int u, int fa)
{
    for (auto v : tr[u])
    {
        if (v == fa)
        {
            continue;
        }
        dfs(v, u);
    }
    tms++;
    for (int i = 0; i < siz[u]; i++)
    {
        tag[cl[u][i]] = tms;
        tag0[cl[u][i]] = i;
    }
    for (auto v : tr[u])
    {
        if (v == fa)
        {
            continue;
        }
        id[v].resize(siz[v]);
        siz0[v] = 0;
        for (int i = 0; i < siz[v]; i++)
        {
            id[v][i] = tag[cl[v][i]] == tms ? tag0[cl[v][i]] : --siz0[v];
        }
    }
}
int dp(int u, int fa, int s)
{
    if (vis[u][s])
    {
        return f[u][s];
    }
    for (int i = 0; i < siz[u]; i++)
    {
        w[cl[u][i]] = s >> i & 1;
    }
    for (auto i : has[u])
    {
        int res = 0;
        for (int j = 0; j < a[i].size(); j++)
        {
            res |= b[i][j] > 0 ? w[a[i][j]] : !w[a[i][j]];
        }
        if (res == 0)
        {
            vis[u][s] = 1;
            f[u][s] = inf;
            return inf;
        }
    }
    int sum = 0;
    for (auto v : tr[u])
    {
        if (v == fa)
        {
            continue;
        }
        int res = inf;
        for (int s0 = 0; s0 < (1 << -siz0[v]); s0++)
        {
            int tmp = 0, t = 0;
            for (int i = 0; i < siz[v]; i++)
            {
                if (id[v][i] >= 0)
                {
                    t |= (s >> id[v][i] & 1) << i;
                }
                else
                {
                    t |= (s0 >> -(id[v][i] + 1) & 1) << i;
                    tmp += c[cl[v][i]] * (t >> i & 1 ^ bit[cl[v][i]]);
                    ;
                }
            }
            tmp += dp(v, u, t);
            res = std::min(res, tmp);
        }
        sum += res;
        if (sum >= inf)
        {
            sum = inf;
            break;
        }
    }
    vis[u][s] = 1;
    f[u][s] = sum;
    return sum;
}

int main()
{
    for (int T = read(); T; T--)
    {
        memset(e, 0, sizeof(e));
        memset(bln, 0, sizeof(bln));
        memset(vis, 0, sizeof(vis));
        n = read();
        m = read();
        k = read();
        all = 1 << k;
        scanf("%s", str + 1);
        for (int u = 1; u <= n; u++)
        {
            c[u] = read();
            bit[u] = str[u] - '0';
            cl[u].clear();
            tr[u].clear();
            has[u].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int siz = read();
            a[i].resize(siz);
            b[i].resize(siz);
            for (int j = 0; j < siz; j++)
            {
                a[i][j] = read();
                b[i][j] = a[i][j] > 0 ? 1 : -1;
                a[i][j] *= b[i][j];
            }
            for (auto u : a[i])
            {
                for (auto v : a[i])
                {
                    if (u == v)
                    {
                        continue;
                    }
                    e[u][v] = e[v][u] = 1;
                }
            }
        }
        for (int u = n; u >= 1; u--)
        {
            for (int i = u - 1; i >= 1; i--)
            {
                for (int j = i - 1; j >= 1; j--)
                {
                    e[i][j] |= e[u][i] & e[u][j];
                    e[j][i] |= e[i][j];
                }
            }
        }
        mcs();
        for (int i = 0; i < n; i++)
        {
            int u = pe[i];
            for (int v = 1; v <= n; v++)
            {
                if (e[u][v] && rk[v] > i)
                {
                    cl[u].push_back(v);
                }
            }
            cl[u].push_back(u);
            siz[u] = cl[u].size();
        }
        tot = 0;
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v < u; v++)
            {
                int w = intersect(cl[u], cl[v]).size();
                if (siz[u] == w)
                {
                    vis[u][all] = 1;
                }
                if (siz[v] == w)
                {
                    vis[v][all] = 1;
                }
                edg[tot++] = (Edge){
                    u, v, w};
            }
        }
        std::sort(edg, edg + tot);
        std::iota(anc + 1, anc + n + 1, 1);
        for (int i = 0; i < tot; i++)
        {
            int u = edg[i].u, v = edg[i].v, w = edg[i].w;
            if (vis[u][all] || vis[v][all] || find(u) == find(v))
            {
                continue;
            }
            anc[find(u)] = find(v);
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
        for (int u = 1; u <= n; u++)
        {
            if (vis[u][all])
            {
                continue;
            }
            rt = u;
            for (int i = 0; i < m; i++)
            {
                if (bln[i])
                {
                    continue;
                }
                if (intersect(cl[u], a[i]).size() != a[i].size())
                {
                    continue;
                }
                has[u].push_back(i);
                bln[i] = u;
            }
        }
        dfs(rt, 0);
        ans = inf;
        for (int s = 0; s < (1 << siz[rt]); s++)
        {
            int tmp = 0;
            for (int i = 0; i < siz[rt]; i++)
            {
                tmp += c[cl[rt][i]] * (s >> i & 1 ^ bit[cl[rt][i]]);
            }
            tmp += dp(rt, 0, s);
            ans = std::min(ans, tmp);
        }
        if (ans >= inf)
        {
            puts("-1");
            continue;
        }
        printf("%d\n", ans);
    }
    return 0;
}
