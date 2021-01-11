// Problem Statement: https://www.codechef.com/JAN21B/problems/TILESQRS/

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
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define Pii pair<int, int>
#define pb push_back
#define ll long long
#define ld long double
#define fo(i, v, e) for (v = i; v < e; v++)
#define rfo(i, v, e) for (v = i; v > e; v--)
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define vl vector<ll>
#define sz(x) (ll) x.size()
#define vvl vector<vl>
#define vpl vector<pll>
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define pqi priority_queue<int>
#define pq priority_queue
#define yes printf("YES\n")
#define no printf("NO\n")
using namespace std;

template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}

const ll mod = 1000000007;
vl gray = {0, 1, 3, 2, 6, 7, 5, 4, 12, 13, 15, 14, 10, 11, 9, 8};
ll xxx;
vvl mat;

ll logc(ll n, ll i = 1)
{
    fo(0, i, 5)
    {
        if ((1ll << i) == n)
            return i;
    }
    return 0;
}

ll ask(ll x, ll y)
{
    mat[x][y] = (mat[x][y] + 1) % 2;
    cout << "1 " << x + 1 << ' ' << y + 1 << endl;
    cin >> xxx;
    assert(xxx != -1);
    return xxx;
}

ll inv(ll n)
{
    return 1 - n;
}

pll decode(ll n, ll j)
{
    if (n == 0)
        return {0, j - 1};
    if (n == 1)
        return {0, j};
    return {1, j};
}

pll decode2(ll n, ll j)
{
    if (n == 0)
        return {j - 1, 0};
    if (n == 1)
        return {j, 0};
    return {j, 1};
}

void harry()
{
    ll n, q, k, i, j, x, y;
    ill3(n, q, k);
    vl arr(16, 0);
    arr[0] = k;
    mat = vvl(n, vl(n, 0));
    fo(1, i, 16)
    {
        ll temp = logc(gray[i] ^ gray[i - 1]);
        arr[gray[i]] = ask(temp / 2, temp % 2);
    }

    mat[0][1] = (mat[0][1] + 1) % 2;
    mat[1][0] = (mat[1][0] + 1) % 2;
    fo(0, i, 16)
    {
        ll temp = arr[i], flag = true;
        fo(0, j, 4)
        {
            if (arr[(i ^ (1ll << j))] >= temp)
                flag = false;
        }
        if (flag)
        {
            fo(0, j, 4)
            {
                if ((i & (1ll << j)))
                    mat[j / 2][j % 2] = inv(mat[j / 2][j % 2]);
            }
            break;
        }
    }

    // processing rows
    fo(2, x, n)
    {
        if (mat[1][x - 1] != 1)
            arr[0] = ask(1, x - 1);

        mat[0][x - 1] = 0;
        arr[0] = xxx;
        fo(1, i, 8)
        {
            ll temp = logc(gray[i] ^ gray[i - 1]);
            auto it = decode(temp, x);
            arr[gray[i]] = ask(it.first, it.second);
        }

        mat[0][x] = (1 + mat[0][x]) % 2;
        fo(0, i, 8)
        {
            ll temp = arr[i], flag = true;
            fo(0, j, 3)
            {
                if (arr[(i ^ (1ll << j))] >= temp)
                    flag = false;
            }
            if (flag)
            {
                fo(0, j, 3)
                {
                    if ((i & (1ll << j)))
                    {
                        auto it = decode(j, x);
                        mat[it.first][it.second] = inv(mat[it.first][it.second]);
                    }
                }
                break;
            }
        }
    }
    // processing cols
    //////////////////////////////////////////////////////////////////////////////////////////

    fo(2, x, n)
    {
        if (mat[x - 1][1] != 1)
            arr[0] = ask(x - 1, 1);
        mat[x - 1][0] = 0;
        arr[0] = xxx;
        fo(1, i, 8)
        {
            ll temp = logc(gray[i] ^ gray[i - 1]);
            auto it = decode2(temp, x);
            arr[gray[i]] = ask(it.first, it.second);
        }
        mat[x][0] = (mat[x][0] + 1) % 2;
        fo(0, i, 8)
        {
            ll temp = arr[i], flag = true;
            fo(0, j, 3)
            {
                if (arr[(i ^ (1ll << j))] >= temp)
                    flag = false;
            }
            if (flag)
            {
                fo(0, j, 3)
                {
                    if (i & (1ll << j))
                    {
                        auto it = decode2(j, x);
                        mat[it.first][it.second] = inv(mat[it.first][it.second]);
                    }
                }
                break;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////

    fo(2, i, n)
    {
        fo(2, j, n)
        {
            ll temp = xxx;
            if (mat[i - 1][j - 1] != 0)
                temp = ask(i - 1, j - 1);
            if (mat[i - 1][j] % 2 != 1)
                temp = ask(i - 1, j);
            if (mat[i][j - 1] % 2 != 1)
                temp = ask(i, j - 1);
            ll temp2 = ask(i, j);
            // assert(temp!=temp2);
            mat[i][j] = (temp > temp2 ? 1 : 0);
        }
    }
    cout << 2 << endl;
    fo(0, i, n)
    {
        fo(0, j, n)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    ll res;
    ill(res);
    if (res == -1)
        exit(0);
    ravireddy07;
}

int main()
{
    ll t;
    ill(t);
    while (t--)
        harry();
    return 0;
}
