// Problem Statement: https://www.codechef.com/MARCH21B/problems/COLGLF4

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, Nmax = 2e5, LG = 20;

int cnt[Nmax + 5], niv[Nmax + 5], vaz[Nmax + 5], ans[Nmax + 5], sum[LG][Nmax + 5], level[LG][Nmax + 5], subTree[LG][Nmax + 5], root, centroid, mxlvl;
vector<int> v[Nmax + 5], trees[Nmax + 5], aib[Nmax + 5];
vector<vector<int>> aibScad[Nmax + 5];

int pw(int a, int b)
{
    int sol = 1;
    for (int i = 1; i <= b; i <<= 1)
    {
        if (b & i)
            sol = (1LL * sol * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return sol;
}

void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
    else if (a < 0)
        a += mod;
}

void aib_update(int nod, int poz, int val)
{
    for (int i = poz; i < aib[nod].size(); i += i & (-i))
        add(aib[nod][i], val);
}

int aib_query(int nod, int poz)
{
    int s = 0;
    for (int i = poz; i > 0; i -= i & (-i))
        add(s, aib[nod][i]);
    return s;
}

void aibScad_update(int x, int y, int poz, int val)
{
    for (int i = poz; i < aibScad[x][y].size(); i += i & (-i))
        add(aibScad[x][y][i], val);
}

int aibScad_query(int x, int y, int poz)
{
    int s = 0;
    for (int i = poz; i > 0; i -= i & (-i))
        add(s, aibScad[x][y][i]);
    return s;
}

void calcCnt(int nod, int tata)
{
    cnt[nod] = 1;
    for (int vec : v[nod])
        if (vec != tata && !vaz[vec])
        {
            calcCnt(vec, nod);
            cnt[nod] += cnt[vec];
        }
}

void findCent(int nod, int tata)
{
    int ok = 1;
    for (int vec : v[nod])
        if (vec != tata && !vaz[vec])
        {
            findCent(vec, nod);
            if (cnt[vec] > cnt[root] / 2)
                ok = 0;
        }
    if (nod != root && cnt[root] - cnt[nod] > cnt[root] / 2)
        ok = 0;
    if (ok)
        centroid = nod;
}

void dfs(int nod, int tata, int lvl, int ps, int rad, int nrSubtree)
{
    mxlvl = max(mxlvl, lvl);
    level[ps][nod] = lvl;
    subTree[ps][nod] = nrSubtree;
    trees[nod].push_back(rad);
    for (int vec : v[nod])
        if (vec != tata && !vaz[vec])
        {
            sum[ps][vec] = (1LL * sum[ps][nod] * (v[nod].size() - 1)) % mod;
            dfs(vec, nod, lvl + 1, ps, rad, nrSubtree);
        }
}

void makeCentroids(int nod, int lvl)
{
    calcCnt(nod, 0);
    root = nod;
    findCent(nod, 0);

    niv[centroid] = lvl;
    sum[lvl][centroid] = 1;
    trees[centroid].push_back(centroid);
    level[lvl][centroid] = 0;
    int nr = 0, maximumLvl = 0;
    for (int vec : v[centroid])
        if (!vaz[vec])
        {
            mxlvl = 0;
            sum[lvl][vec] = 1;
            dfs(vec, centroid, 1, lvl, centroid, nr);
            aibScad[centroid].push_back({});
            aibScad[centroid][nr].resize(mxlvl + 1, 0);
            nr++;
            maximumLvl = max(maximumLvl, mxlvl);
        }
    aib[centroid].resize(maximumLvl + 1, 0);
    vaz[centroid] = 1;
    int aux = centroid;
    for (int vec : v[aux])
        if (!vaz[vec])
            makeCentroids(vec, lvl + 1);
}

void update(int nod, int d)
{
    for (int cent : trees[nod])
    {
        if (nod == cent)
        {
            add(ans[cent], 1);
            int toAdd = pw(v[cent].size(), mod - 2);
            //if (v[cent].size() > 2) toAdd = (1LL * toAdd * pw(v[cent].size() - 1, mod - 2)) % mod;
            aib_update(cent, 1, toAdd);
            aib_update(cent, d + 1, -toAdd);
        }
        else
        {
            int l = niv[cent];
            int toAdd = (1LL * sum[l][nod] * (v[nod].size())) % mod;
            if (level[l][nod] <= d)
                add(ans[cent], pw(toAdd, mod - 2));
            toAdd = (1LL * toAdd * (v[cent].size() - 1)) % mod;
            toAdd = pw(toAdd, mod - 2);
            int ramas = d - level[l][nod];
            if (ramas > 0)
            {
                aib_update(cent, 1, toAdd);
                aib_update(cent, ramas + 1, -toAdd);
                aibScad_update(cent, subTree[l][nod], 1, -toAdd);
                aibScad_update(cent, subTree[l][nod], ramas + 1, toAdd);
            }
        }
    }
}

int query(int nod)
{
    int sol = ans[nod];
    for (int cent : trees[nod])
    {
        if (nod == cent)
            continue;
        int l = niv[cent];
        int toAdd = aib_query(cent, level[l][nod]);
        add(toAdd, aibScad_query(cent, subTree[l][nod], level[l][nod]));
        toAdd = (1LL * toAdd * pw(sum[l][nod], mod - 2)) % mod;
        add(sol, toAdd);
    }
    return sol;
}

int main()
{
    int n, q, x, y, a, b, t;
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    makeCentroids(1, 0);
    int last = 0;
    while (q--)
    {
        scanf("%d%d", &t, &a);
        if (t == 1)
        {
            scanf("%d", &b);
            x = (last + a) % n + 1;
            y = (last + b) % n + 1;
            update(x, y);
        }
        else
        {
            x = (last + a) % n + 1;
            last = query(x);
            printf("%d\n", last);
        }
    }
    return 0;
}
