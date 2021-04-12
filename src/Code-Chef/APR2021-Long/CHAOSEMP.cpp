// Problem Statement: https://www.codechef.com/APRIL21B/problems/CHAOSEMP

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

#define LIM 1E18

void trigger22Handler(ll X1, ll Y1, ll X2, ll Y2)
{
    string response = "INIT";
    cout << "2 " << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;
    cin >> response;
    if (response == "O")
        return;
    cout << "2 " << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;
    cin >> response;
    assert(response == "O");
}

void trigger23Handler(ll X1, ll Y1, ll X2, ll Y2)
{
    string response = "INIT";
    cout << "2 " << X1 << " " << Y1 << " " << X2 << " " << Y2 - 1 << endl;
    cin >> response;
    if (response == "O")
        return;
    if (response == "IN")
        cout << "2 " << X1 << " " << Y1 << " " << X2 << " " << Y2 - 1 << endl;
    else
        cout << "2 " << X1 << " " << Y2 - 1 << " " << X2 << " " << Y2 + 1 << endl;
    cin >> response;
    assert(response == "O");
}

void trigger32Handler(ll X1, ll Y1, ll X2, ll Y2)
{
    string response = "INIT";
    cout << "2 " << X1 << " " << Y1 << " " << X2 - 1 << " " << Y2 << endl;
    cin >> response;
    if (response == "O")
        return;
    if (response == "IN")
        cout << "2 " << X1 << " " << Y1 << " " << X2 - 1 << " " << Y2 << endl;
    else
        cout << "2 " << X2 - 1 << " " << Y1 << " " << X2 + 1 << " " << Y2 << endl;
    cin >> response;
    assert(response == "O");
}

void trigger33Handler(ll X1, ll Y1, ll X2, ll Y2)
{
    string response = "INIT";
    cout << "2 " << X1 << " " << Y1 << " " << X2 << " " << Y2 - 1 << endl;
    cin >> response;
    if (response == "O")
        return;
    if (response == "IN")
        trigger32Handler(X1, Y1, X2, Y2 - 1);
    else
        trigger32Handler(X1, Y2 - 1, X2, Y2 + 1);
}

bool isTerminal(ll X1, ll Y1, ll X2, ll Y2)
{
    if (X2 - X1 < 4 && Y2 - Y1 < 4)
    {
        if (X2 - X1 == 2)
        {
            if (Y2 - Y1 == 2)
                trigger22Handler(X1, Y1, X2, Y2);
            else
                trigger23Handler(X1, Y1, X2, Y2);
        }
        else
        {
            if (Y2 - Y1 == 2)
                trigger32Handler(X1, Y1, X2, Y2);
            else
                trigger33Handler(X1, Y1, X2, Y2);
        }
        return true;
    }
    return false;
}

void boxUpdater(string response, ll &X1, ll &Y1, ll &X2, ll &Y2, ll midX, ll midY, int D = 1)
{
    if (response == "PY")
    {
        X1 -= D;
        X2 = midX - 1 + D;
        Y1 = midY - D;
        Y2 = midY + D;
    }

    if (response == "NY")
    {
        X1 = midX + 1 - D;
        X2 += D;
        Y1 = midY - D;
        Y2 = midY + D;
    }

    if (response == "XP")
    {
        X1 = midX - D;
        X2 = midX + D;
        Y1 -= D;
        Y2 = midY - 1 + D;
    }

    if (response == "XN")
    {
        X1 = midX - D;
        X2 = midX + D;
        Y1 = midY + 1 - D;
        Y2 += D;
    }

    if (response == "PP")
    {
        X1 -= D;
        X2 = midX - 1 + D;
        Y1 -= D;
        Y2 = midY - 1 + D;
    }

    if (response == "PN")
    {
        X1 -= D;
        X2 = midX - 1 + D;
        Y1 = midY + 1 - D;
        Y2 += D;
    }

    if (response == "NP")
    {
        X1 = midX + 1 - D;
        X2 += D;
        Y1 -= D;
        Y2 = midY - 1 + D;
    }

    if (response == "NN")
    {
        X1 = midX + 1 - D;
        X2 += D;
        Y1 = midY + 1 - D;
        Y2 += D;
    }
}

bool trigger1Solver()
{
    ll X1 = -LIM, Y1 = -LIM, X2 = LIM, Y2 = LIM; // Denotes current box of presence
    string response = "INIT";
    while (response != "FAILED")
    {
        if (isTerminal(X1, Y1, X2, Y2))
            return true;
        ll midX = (X1 + X2) / 2;
        ll midY = (Y1 + Y2) / 2;
        cout << "1 " << midX << " " << midY << endl;
        cin >> response;
        if (response == "O")
            return true;

        // Based on response, update the box
        boxUpdater(response, X1, Y1, X2, Y2, midX, midY);
    }
    return false;
}

bool trigger0Solver()
{
    ll X1 = -LIM, Y1 = -LIM, X2 = LIM, Y2 = LIM; // Denotes current box of presence
    string response = "INIT";
    while (response != "FAILED")
    {
        ll midX = (X1 + X2) / 2;
        ll midY = (Y1 + Y2) / 2;
        cout << "1 " << midX << " " << midY << endl;
        cin >> response;
        if (response == "O")
            return true;

        // Based on response, update the box
        boxUpdater(response, X1, Y1, X2, Y2, midX, midY, 0);
    }
    return false;
}

bool harry(int D)
{
    return D ? trigger1Solver() : trigger0Solver();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T, Q, D;
    ii3(T, Q, D);
    while (T--)
    {
        if (!harry(D))
            return 0;
    }
    return 0;
}
