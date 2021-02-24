// Problem Statement: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043aee7

// Accepted Solution

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int N = 5e4 + 26 + 5;

int n, q;
string s[N];
vector<int> g[N];
bool vis[26][N];
int dist[26][N];

void bfs(int k, int idx)
{
    queue<int> q;
    q.push(k);
    for (int i = 1; i <= n + 26; i++)
    {
        dist[idx][i] = 1e9;
        vis[idx][i] = 0;
    }
    vis[idx][k] = 1;
    dist[idx][k] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : g[node])
        {
            if (!vis[idx][it])
            {
                dist[idx][it] = dist[idx][node] + 1;
                vis[idx][it] = 1;
                q.push(it);
            }
        }
    }
}

int32_t main()
{
    int t;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        tc++;
        cin >> n >> q;
        int off = n + 1;
        for (int i = 1; i <= n + 26; i++)
            g[i].clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            set<char> st;
            for (auto &it : s[i])
                st.insert(it);
            s[i] = "";
            for (auto &it : st)
                s[i] += it;
            for (auto &it : s[i])
            {
                g[i].push_back(off + it - 'A');
                g[off + it - 'A'].push_back(i);
            }
        }
        for (char ch = 'A'; ch <= 'Z'; ch++)
            bfs(off + ch - 'A', ch - 'A');
        cout << "Case #" << tc << ": ";
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            int ans = 1e9;
            for (int i = 0; i < 26; i++)
                ans = min(ans, dist[i][x] + dist[i][y]);
            if (ans > 1e6)
                cout << -1 << " ";
            else
                cout << 1 + ans / 2 << " ";
        }
        cout << endl;
    }
    return 0;
}

// TLE-Brute Force
/*
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool fri(string a, string b)
{
    for (ll j = 0; j < a.length(); j++)
        for (ll k = 0; k < b.length(); k++)
            if (a[j] == b[k])
                return true;
    return false;
}

ll f(vector<string> names, ll a, ll b)
{
    vector<string> af, bf;
    bool exit1, exit2;
    for (ll i = 0; i < names.size(); i++)
    {
        exit1 = 0, exit2 = 0;
        if (i != a || i != b)
        {
            string aa = names[a], bb = names[i], cc = names[b];
            for (int j = 0; j < bb.length(); j++)
            {
                if (!exit1)
                    for (int k = 0; k < aa.size(); k++)
                    {
                        if (aa[k] == bb[j])
                        {
                            af.push_back(bb);
                            exit1 = 1;
                            break;
                        }
                    }
                if (!exit2)
                    for (ll k = 0; k < cc.length(); k++)
                    {
                        if (bb[j] == cc[k])
                        {
                            bf.push_back(bb);
                            exit2 = 1;
                            break;
                        }
                    }
            }
        }

        for (ll i = 0; i < af.size(); i++)
            for (ll j = 0; j < bf.size(); j++)
                if (af[i] == bf[j])
                    return 3;
    }
    return 0;
}

int main()
{
    ll t;
    scanf("%lld", &t);
    for (ll tt = 0; tt < t; tt++)
    {
        ll n, q;
        scanf("%lld%lld", &n, &q);
        vector<string> names;
        string d = "";
        for (ll i = 0; i < n; i++)
        {
            cin >> d;
            names.push_back(d);
        }

        ll f1, f2;
        bool friends = 0;
        ll res = 0;
        printf("Case #%lld:", tt + 1);
        for (ll x = 0; x < q; x++)
        {
            scanf("%lld%lld", &f1, &f2);
            for (ll i = 0; i < q; i++)
            {
                friends = fri(names[f1 - 1], names[f2 - 1]);
                if (friends)
                {
                    res = 2;
                    printf(" %lld", res);
                    break;
                }
                else if (!friends)
                {
                    res = f(names, f1 - 1, f2 - 1);
                    if (res == 0)
                    {
                        res = -1;
                        printf(" %lld", res);
                        break;
                    }
                    printf(" %lld", res);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
*/
