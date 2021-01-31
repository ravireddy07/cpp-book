// Problem Statement: https://www.codechef.com/JAN21B/problems/TILESQRS/

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#define fo(i, v, e) for (v = i; v < e; v++)
#define rfo(i, v, e) for (v = i; v > e; v--)
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define vvl vector<vl>
#define vpl vector<pll> #include<bits / stdc++.h>
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
#define unmp unordered_map
#define pqi priority_queue<int>
#define pq priority_queue
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
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

// Optimal Solution
vector<int> a{0, 1, 3, 2, 6, 7, 5, 4};
vector<int> c{3, 2, 3, 1, 3, 2, 3};

pair<int, int> dir(int x)
{
    if (x == 1)
        return {0, 1};
    else if (x == 2)
        return {1, 0};
    else
        return {1, 1};
}

vector<int> a2{0, 1, 3, 2};
vector<int> c2{2, 1, 2};

pair<int, int> dir_col(int x)
{
    if (x == 1)
        return {0, 1};
    return {1, 1};
}

pair<int, int> dir_row(int x)
{
    if (x == 1)
        return {1, 0};
    return {1, -1};
}

int ans[205][205];

void set_block(int i, int j)
{
    ans[i][j] = 0;
    ans[i + 1][j] = 1;
    ans[i][j + 1] = 1;
    ans[i + 1][j + 1] = 0;
}

int ask(int i, int j)
{
    printf("1 %d %d\n", i, j);
    int x;
    ii(x);
    return x;
}

void func()
{
    int n, q, prev;
    ii3(n, q, prev);
    int i, j, k, new_k;
    int x, y, z;
    int dx, dy;

    for (i = 1; i < n; i += 2)
    {
        for (j = 1; j < n; j += 2)
        {
            x = ask(i, j);
            if (i == 1 || j == 1)
            {
                if (x == prev - 1)
                    prev = ask(i, j);
                else if (x == prev + 1)
                    prev = x;
                else
                {
                    for (auto it : c)
                    {
                        dx = dir(it).first;
                        dy = dir(it).second;
                        x = ask(i + dx, j + dy);
                        y = ask(i, j);
                        if (y == x - 1)
                        {
                            prev = ask(i, j);
                            break;
                        }
                        else if (y == x + 1)
                        {
                            prev = y;
                            break;
                        }
                    }
                }
            }
            else
            {
                if (x == prev - 2)
                    prev = ask(i, j);
                else if (x == prev + 2)
                    prev = x;
                else
                {
                    for (auto it : c)
                    {
                        dx = dir(it).first;
                        dy = dir(it).second;
                        x = ask(i + dx, j + dy);
                        y = ask(i, j);
                        if (y == x - 2)
                        {
                            prev = ask(i, j);
                            break;
                        }
                        else if (y == x + 2)
                        {
                            prev = y;
                            break;
                        }
                    }
                }
            }
            set_block(i, j);
        }
    }

    if (n % 2 == 1)
    {
        i = n - 1;
        for (j = 1; j <= n - 1; j++)
        {
            if (j % 2 == 1)
            {
                set_block(i, j);
                prev = ask(i, j);
            }
            else
            {
                new_k = ask(i, j);
                if (new_k > prev)
                {
                    prev = new_k;
                    continue;
                }

                prev = new_k;
                for (auto it : c2)
                {
                    dx = dir_row(it).first;
                    dy = dir_row(it).second;

                    new_k = ask(i + dx, j + dy);
                    if (new_k > prev)
                    {
                        prev = new_k;
                        break;
                    }
                }
            }
        }

        j = n - 1;
        for (i = n - 2; i >= 1; i--)
        {
            if (i % 2 == 1)
            {
                set_block(i, j);
                new_k = ask(i, j);
                if (new_k > prev)
                {
                    prev = new_k;
                    continue;
                }

                prev = new_k;

                for (auto it : c2)
                {
                    dx = dir_col(it).first;
                    dy = dir_col(it).second;

                    new_k = ask(i + dx, j + dy);
                    if (new_k > prev)
                    {
                        prev = new_k;
                        break;
                    }
                }
            }
            else
                prev = ask(i, j);
        }

        i = n - 1;
        j = n - 1;

        prev = ask(i, j);
        prev = ask(i + 1, j);
        new_k = ask(i, j + 1);

        if (new_k > prev)
        {
        }
        else
            prev = ask(i + 1, j + 1);
        set_block(i, j);
    }

    printf("2\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }

    int ver;
    ii(ver);
    if (ver == -1)
        exit(0);
    ravireddy07;
}

// Accepted Solution
const ll mod = 1000000007;
vl gray = {0, 1, 3, 2, 6, 7, 5, 4, 12, 13, 15, 14, 10, 11, 9, 8};
ll xxx;
vvl mat;

ll logc(ll n, ll i = 1)
{
    fo(0, i, 5) if ((1ll << i) == n) return i;
    return 0;
}

ll ask1(ll x, ll y)
{
    mat[x][y] = (mat[x][y] + 1) % 2;
    printf("1 %lld %lld\n", x + 1, y + 1);
    ii(xxx);
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
            arr[0] = ask1(1, x - 1);

        mat[0][x - 1] = 0;
        arr[0] = xxx;
        fo(1, i, 8)
        {
            ll temp = logc(gray[i] ^ gray[i - 1]);
            auto it = decode(temp, x);
            arr[gray[i]] = ask1(it.first, it.second);
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
