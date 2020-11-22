// Problem Statement: https://atcoder.jp/contests/abc184/tasks/abc184_f

#include <bits/stdc++.h>
using namespace std;

// Missing 14 Test cases out of 35
#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli res = 0, t, n, temp = 0;

lli Combi(vector<lli> a, int reqLen, lli s, lli currLen, bool check[])
{
    if (currLen > reqLen)
        return res;
    else if (currLen == reqLen)
    {
        temp = 0;
        for (int i = 0; i < n; i++)
            if (check[i] == true)
                temp += a[i];

        if (temp <= t and temp >= res)
            res = temp;
        return temp;
    }

    if (s == n)
        return res;
    check[s] = true;
    Combi(a, reqLen, s + 1, currLen + 1, check);
    check[s] = false;
    Combi(a, reqLen, s + 1, currLen, check);
    return res;
}

int main()
{
    cin >> n >> t;
    vector<lli> v(n);
    bool check[n];

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        res += v[i];
        check[i] = 0;
    }

    if (res <= t)
    {
        printf("%lld\n", res);
        return 0;
    }
    res = 0;
    for (int i = 0; i < n; i++)
        res = Combi(v, i + 1, 0, 0, check);
    cout << res << endl;
    return 0;
}

// Accepted Solution
int n, t, a[100];
vector<int> l, r;

void dfs(int dep, int sum)
{
    if (sum > t)
        return;
    if (dep > (n >> 1))
    {
        l.push_back(sum);
        return;
    }
    dfs(dep + 1, sum);
    dfs(dep + 1, sum + a[dep]);
}

void dfs2(int dep, int sum)
{
    if (sum > t)
        return;
    if (dep > n)
    {
        r.push_back(sum);
        return;
    }
    dfs2(dep + 1, sum);
    dfs2(dep + 1, sum + a[dep]);
}

int main(void)
{
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
    }
    dfs(1, 0);
    dfs2((n >> 1) + 1, 0);
    sort(r.begin(), r.end());
    int ans = 0;
    for (auto i : l)
    {
        ans = max(ans, i + *(upper_bound(r.begin(), r.end(), t - i) - 1));
    }
    printf("%d\n", ans);
    return 0;
}
