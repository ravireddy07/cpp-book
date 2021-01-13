// Problem Statement: https://www.codechef.com/JAN21B/problems/CURMAT/

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
using ll = long long;
using std::get;
using std::make_pair;
using std::make_tuple;
using std::map;
using std::pair;
using std::stack;
using std::tuple;
using std::vector;

constexpr int kMaxN = 100000, kMaxQ = 100000;
constexpr int kMod = 1000000007;
int n, q, p;
int pow_of_p[kMaxN * 2];
tuple<int, int, int> vec[kMaxQ];
int ans[kMaxQ];
int par[kMaxN * 2], sz[kMaxN * 2], weight[kMaxN * 2], inv_weight[kMaxN * 2];
int cnt_of_components, cnt_of_bad_edges;

int powMod(int a, int b, int m)
{
    int res = 1, tmp = a;
    while (b)
    {
        if (b & 1)
            res = (ll)res * tmp % m;
        b >>= 1;
        tmp = (ll)tmp * tmp % m;
    }
    return res;
}

int calcInv(int a, int m) { return powMod(a, m - 2, m); }

#define ROW(x) (x)
#define COL(x) (n + (x))

struct Node
{
    vector<int> info;
    Node *child[2];
    Node() { this->child[0] = this->child[1] = nullptr; }
};

Node *build(int l, int r)
{
    Node *res = new Node;
    if (l + 1 < r)
    {
        int mid = (l + r) >> 1;
        res->child[0] = build(l, mid);
        res->child[1] = build(mid, r);
    }
    return res;
}

void modify(int l, int r, int i, Node *pos, int pl, int pr)
{
    if (l <= pl && pr <= r)
        pos->info.push_back(i);
    else
    {
        int pmid = (pl + pr) >> 1;
        if (l < pmid)
            modify(l, r, i, pos->child[0], pl, pmid);
        if (r > pmid)
            modify(l, r, i, pos->child[1], pmid, pr);
    }
}

int find(int z) { return z == par[z] ? z : find(par[z]); }

int mul_to_root(int z)
{
    return z == par[z] ? 1 : (ll)weight[z] * mul_to_root(par[z]) % p;
}

stack<tuple<int, int, int, int, int>> stk;

void merge(int x, int y, int v)
{
    int zx = ROW(x);
    int zy = COL(y);

    int root_of_zx = find(zx);
    int root_of_zy = find(zy);

    if (root_of_zx != root_of_zy)
    {
        if (sz[root_of_zx] < sz[root_of_zy])
        {
            stk.emplace(root_of_zx, root_of_zy, par[root_of_zx], sz[root_of_zx],
                        weight[root_of_zx]);

            int mulzx = mul_to_root(zx);
            int mulzy = mul_to_root(zy);
            int new_v = (ll)v * mulzy % p * calcInv(mulzx, p) % p;
            weight[root_of_zx] = new_v;

            par[root_of_zx] = root_of_zy;
            sz[root_of_zy] += sz[root_of_zx];
            sz[root_of_zx] = 0;
        }
        else
        {
            stk.emplace(root_of_zy, root_of_zx, par[root_of_zy], sz[root_of_zy],
                        weight[root_of_zy]);

            int mulzy = mul_to_root(zy);
            int mulzx = mul_to_root(zx);
            int new_v = (ll)calcInv(v, p) * mulzx % p * calcInv(mulzy, p) % p;
            weight[root_of_zy] = new_v;

            par[root_of_zy] = root_of_zx;
            sz[root_of_zx] += sz[root_of_zy];
            sz[root_of_zy] = 0;
        }
        --cnt_of_components;
    }
    else
    {
        int mulzx = mul_to_root(zx);
        int mulzy = mul_to_root(zy);
        int mul = (ll)mulzx * calcInv(mulzy, p) % p;
        mul = (ll)mul * calcInv(v, p) % p;

        if (mul == 1)
        {
            // not influenced
            stk.emplace(-1, -1, -1, -1, -1);
        }
        else
        {
            // set to zero
            cnt_of_bad_edges++;
            stk.emplace(-2, -2, -2, -2, -2);
        }
    }
}

void split()
{
    auto top = stk.top();
    stk.pop();
    if (get<0>(top) == -1)
    {
        // nothing
    }
    else if (get<0>(top) == -2)
    {
        // unset to zero
        --cnt_of_bad_edges;
    }
    else
    {
        int from = get<0>(top);
        int to = get<1>(top);
        int old_par = get<2>(top);
        int old_sz = get<3>(top);
        int old_w = get<4>(top);
        ++cnt_of_components;
        sz[to] -= old_sz;
        par[from] = old_par;
        sz[from] = old_sz;
        weight[from] = old_w;
    }
}

void solve(Node *pos, int pl, int pr)
{
    for (auto it = pos->info.begin(); it != pos->info.end(); ++it)
    {
        int i = *it;
        auto &t = vec[i];
        merge(get<0>(t), get<1>(t), get<2>(t));
    }
    if (pl + 1 < pr)
    {
        int pmid = (pl + pr) >> 1;
        solve(pos->child[0], pl, pmid);
        solve(pos->child[1], pmid, pr);
    }
    else
    {
        ans[pl] = cnt_of_bad_edges > 0 ? 0 : pow_of_p[cnt_of_components - 1];
    }
    for (auto it = pos->info.rbegin(); it != pos->info.rend(); ++it)
    {
        split();
    }
}

int main()
{
    scanf("%d%d%d", &n, &q, &p);
    pow_of_p[0] = 1;
    for (int i = 1; i < n * 2; ++i)
    {
        pow_of_p[i] = (ll)pow_of_p[i - 1] * (p - 1) % kMod;
    }
    Node *root = build(0, q);
    map<pair<int, int>, int> last;
    for (int i = 0, x, y, v; i < q; ++i)
    {
        scanf("%d%d%d", &x, &y, &v);
        --x, --y;
        vec[i] = make_tuple(x, y, v);
        if (last.count(make_pair(x, y)))
        {
            int pre = last[make_pair(x, y)];
            // (x, y) exists for the time range [pre, i)
            modify(pre, i, pre, root, 0, q);
            last.erase(make_pair(x, y));
        }
        else
        {
            last[make_pair(x, y)] = i;
        }
    }
    for (const auto &entry : last)
    {
        int pre = entry.second;
        // (x, y) exists for the time range [pre, q)
        modify(pre, q, pre, root, 0, q);
    }
    for (int i = 0; i < n * 2; ++i)
    {
        par[i] = i;
        sz[i] = 1;
        weight[i] = 1;
    }
    cnt_of_components = n * 2;
    cnt_of_bad_edges = 0;
    solve(root, 0, q);
    for (int i = 0; i < q; ++i)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
