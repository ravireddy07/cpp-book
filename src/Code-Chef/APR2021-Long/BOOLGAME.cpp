// Problem Statement: https://www.codechef.com/APRIL21B/problems/BOOLGAME

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

ll getOverlappingRanges(int i, int j, vector<vector<pair<int, ll>>> &D)
{
    ll sum = 0;
    for (auto elem : D[i])
        sum += elem.first <= j ? elem.second : 0;
    return sum;
}

void harry()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> G(N);
    for (int i = 0; i < N; i++)
        cin >> G[i];

    vector<vector<ll>> prefSum(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++)
    {
        ll curSum = 0;
        for (int j = i; j < N; j++)
        {
            curSum += G[j];
            prefSum[i][j] = curSum;
        }
    }

    vector<vector<pair<int, ll>>> D(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        ii2(u, v);
        u--;
        v--;
        ll d;
        ill(d);
        D[u].push_back({v, d});
    }

    multiset<ll> topK[N][2];
    topK[0][0].insert(0);
    topK[0][1].insert(G[0]);
    for (int i = 1; i < N; i++)
    {
        // Not taking ith value
        for (auto elem : topK[i - 1][0])
            topK[i][0].insert(elem);

        for (auto elem : topK[i - 1][1])
        {
            topK[i][0].insert(elem);
            if (topK[i][0].size() > K)
                topK[i][0].erase(topK[i][0].begin());
        }

        // Taking ith value
        ll prevSum = 0;
        for (int prev = i - 1; prev >= 0; prev--)
        {
            prevSum += getOverlappingRanges(prev + 1, i, D);
            for (auto elem : topK[prev][0])
            {
                topK[i][1].insert(elem + prefSum[prev + 1][i] + prevSum);
                if (topK[i][1].size() > K)
                    topK[i][1].erase(topK[i][1].begin());
            }
        }

        prevSum += getOverlappingRanges(0, i, D);
        topK[i][1].insert(prefSum[0][i] + prevSum);
        if (topK[i][1].size() > K)
            topK[i][1].erase(topK[i][1].begin());
    }

    multiset<ll> answer;
    for (auto elem : topK[N - 1][0])
        answer.insert(elem);
    for (auto elem : topK[N - 1][1])
        answer.insert(elem);

    int counter = 0;
    for (auto it = answer.rbegin(); it != answer.rend(); it++)
    {
        cout << *it << " ";
        counter++;
        if (counter == K)
            break;
    }
    cout << "\n";
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
