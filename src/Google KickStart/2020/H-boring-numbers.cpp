// Problem Statement: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6

/*
// Partilly Accepted
#include <bits/stdc++.h>
#define lli long long int
using namespace std;

bool test(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!i and (int) s[i] % 2 == 0)
            return 1;
        else if ((int)s[i] % 2 == 0 && i % 2 == 0)
            return 1;
        else if ((int)s[i] % 2 != 0 and i % 2 != 0)
            return 1;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    lli l, r;
    lli res;
    for (int tt = 0; tt < t; tt++)
    {
        scanf("%lld%lld", &l, &r);
        res = 0;

        for (lli i = l; i <= r; i++)
        {
            if (i < 10)
            {
                if (i % 2 == 0)
                    res++;
            }
            else
                res += (test(to_string(i))) ? 1 : 0;
        }
        printf("Case #%d: %lld\n", tt + 1, ((r - l) + 1) - res);
    }
    return 0;
}
*/

#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;

const int N = 0;

string l, r;
int dp[20][20][2];

int calc(int pos, int zeros, int small, string &r)
{
    if (pos == r.size())
        return 1;
    int &ans = dp[pos][zeros][small];
    if (ans != -1)
        return ans;
    ans = 0;

    if (pos == zeros)
        ans += calc(pos + 1, zeros + 1, 1, r);

    if ((pos - zeros) % 2 == 0)
    {
        for (int i = 1; i < 10; i += 2)
        {
            if (small || (i < r[pos] - '0'))
                ans += calc(pos + 1, zeros, 1, r);
            else if (i == r[pos] - '0')
                ans += calc(pos + 1, zeros, 0, r);
        }
    }
    else
    {
        for (int i = 0; i < 10; i += 2)
        {
            if (small || (i < r[pos] - '0'))
                ans += calc(pos + 1, zeros, 1, r);
            else if (i == r[pos] - '0')
                ans += calc(pos + 1, zeros, 0, r);
        }
    }
    return ans;
}

void solve(int test)
{
    int L, R;
    int ans;
    cin >> L >> R;
    L--;

    l = to_string(L);
    r = to_string(R);

    mem1(dp);
    ans = calc(0, 0, 0, r);
    mem1(dp);
    ans -= calc(0, 0, 0, l);

    cout << "Case #" << test << ": " << ans << "\n";
}
signed main()
{
    int test = 1;
    int t;
    cin >> t;
    while (t--)
        solve(test++);
    return 0;
}
