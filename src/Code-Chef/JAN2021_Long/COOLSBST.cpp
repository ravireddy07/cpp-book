// Problem Statement: https://www.codechef.com/JAN21B/problems/COOLSBST/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;
int l, r;

int diffarrcount1[300010];
int diffarrcount2[300010];
int twocount[200010];
ll dp2[100010][2], dp4[100010][4];
ll fact[100010];
ll modinv[100010];
int alltwos, allfours, onlytwos;

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll x = binpow(a, b / 2);
    x *= x;
    x %= mod;
    if (b % 2 == 0)
        return x;
    else
        return x * a % mod;
}

ll nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    ll num = fact[n];
    ll denom = modinv[r] * modinv[n - r] % mod;
    return num * denom % mod;
}

ll coeffpref[900][100010];
ll tempcoeff[100010];
int block_size = 120;
int lim = 100010;

void precomp()
{
    for (int i = 0; i < lim; i++)
    {
        if (i % block_size == 0)
        {
            int ind = i / block_size;
            coeffpref[ind][0] = 1;
            tempcoeff[0] = 1;
            int j;
            for (j = 1; j < (i + 1) / 2; j++)
            {
                tempcoeff[j] = nCr(i, j);
                coeffpref[ind][j] = coeffpref[ind][j - 1] + tempcoeff[j];
            }
            if ((i + 1) % 2 == 1)
            {
                coeffpref[ind][j] = coeffpref[ind][j - 1] + nCr(i, j);
                j++;
            }
            for (int k = j - 2; j < i + 1; j++, k--)
            {
                coeffpref[ind][j] = coeffpref[ind][j - 1] + tempcoeff[k];
            }
        }
    }
}

ll calcpref(int n, int k)
{
    k = min(n, k);
    if (n == k)
    {
        ll ans = binpow(2, n);
        return ans;
    }

    if (k <= block_size)
    {
        ll ans = 0;
        for (int i = 0; i <= k; i++)
            ans += nCr(n, i);
        return ans % mod;
    }
    if (n - k <= block_size)
    {
        ll ans = binpow(2, n);
        for (int i = k + 1; i <= n; i++)
            ans -= nCr(n, i);
        return ans % mod;
    }

    int nearest = n / block_size;

    int dist = n % block_size;

    ll ans = 0;
    for (int i = 0; i <= dist; i++)
    {
        if (coeffpref[nearest][k - dist + i] > mod)
            coeffpref[nearest][k - dist + i] %= mod;
        // ans += mul(nCr(dist, i), coeffpref[nearest][k-dist+i]);
        ans += nCr(dist, i) * (coeffpref[nearest][k - dist + i]); //%mod);
        ans %= mod;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int MAXLR = 100010;

    vector<int> primes;
    int sieve[MAXLR] = {0};

    for (int i = 2; i < MAXLR; i++)
    {
        if (sieve[i] == 1)
            continue;
        if (i != 2)
            primes.push_back(i);
        for (int j = i; j < MAXLR; j += i)
            sieve[j] = 1;
    }

    fact[0] = 1;
    for (int i = 1; i < 100010; i++)
        fact[i] = i * fact[i - 1] % mod;
    modinv[100009] = binpow(fact[100009], mod - 2);

    for (int i = 100008; i >= 0; i--)
        modinv[i] = modinv[i + 1] * (i + 1) % mod;

    precomp();

    for (auto x : primes)
    {
        int curcount = 1;
        int i;
        for (i = 3 * x; i < 100030; i += 2 * x)
        {
            diffarrcount1[i - 2 * x] += curcount;
            diffarrcount1[i] -= curcount;
            int temp = i;
            while (temp % x == 0)
            {
                temp /= x;
                curcount++;
            }
        }
        diffarrcount1[i - 2 * x] += curcount;
        diffarrcount1[i] -= curcount;

        curcount = 0;
        for (i = 2 * x; i < 100030; i += 2 * x)
        {
            diffarrcount2[i - 2 * x] += curcount;
            diffarrcount2[i] -= curcount;
            int temp = i;
            while (temp % x == 0)
            {
                temp /= x;
                curcount++;
            }
        }
        diffarrcount2[i - 2 * x] += curcount;
        diffarrcount2[i] -= curcount;
    }

    // for(int i=0; i<100010; i++){
    // 	int cur = 2;
    // 	while(cur <= i){
    // 		twocount[i] += i/cur;
    // 		cur *= 2;
    // 	}
    // }

    // print(twocount, 20);

    for (int i = 1; i < 100030; i++)
    {
        diffarrcount1[i] += diffarrcount1[i - 1];
        diffarrcount2[i] += diffarrcount2[i - 1];
    }

    for (int i = 0; i < 100030; i++)
        diffarrcount2[i] += diffarrcount1[i];

    // dp4[1][1] = 1;
    // dp2[1][1] = 1;
    // for(int i=2; i<100010; i++){
    // 	dp4[i][i%4]++;
    // 	for(int j=0; j<4; j++){
    // 		dp4[i][j] += dp4[i-1][j];
    // 		dp4[i][(j*i)%4] += dp4[i-1][j];
    // 	}
    // 	dp2[i][i%2]++;
    // 	for(int j=0; j<2; j++){
    // 		dp2[i][j] += dp2[i-1][j];
    // 		dp2[i][(j*i)%2] += dp2[i-1][j];
    // 	}
    // }

    // for(int i=0; i<20; i++){
    // 	cout << dp4[i][0] << " ";
    // }
    // cout << "\n";
    // for(int i=0; i<20; i++){
    // 	cout << dp2[i][0] << " ";
    // }
    // cout << "\n";

    for (int tt = 0; tt < t; tt++)
    {
        int a, b;
        // if(tt > 80000)
        // 	break;
        cin >> l >> r >> a >> b;
        assert(0 <= l && l <= r && r <= 100000);
        assert(0 <= a && a <= b && b <= 100000);
        int tot = r - l + 1;
        // debug(t);
        if (a > tot)
        {
            cout << "0\n";
            continue;
        }

        b = min(b, tot);

        pair<int, int> f = {diffarrcount2[r], diffarrcount1[r]};
        pair<int, int> g = {diffarrcount2[l - 1], diffarrcount1[l - 1]};

        f.first -= g.first;
        f.second -= g.second;

        f.first %= mod;
        f.second %= mod;

        alltwos = r / 2 - (l - 1) / 2;
        allfours = r / 4 - (l - 1) / 4;
        onlytwos = alltwos - allfours;

        /*
		
		res = 2*one*nCr(tot-1, a-1) - two*nCr(tot - alltwos - 1, a-1);

		ll fourprimitive = onlytwos*nCr(tot - alltwos, a-1) + 2*nCr(tot - alltwos, a);
		res += 3*nCr(tot, a) - fourprimitive;// (onlytwos+2)*nCr(tot - alltwos, a) ;
		*/
        ll one, two, five, six;
        ll res = 0;
        if (a - 1 == 0)
        {
            one = calcpref(tot - 1, b - 1);
            two = calcpref(tot - alltwos - 1, b - 1);
        }
        else
        {
            one = calcpref(tot - 1, b - 1) - calcpref(tot - 1, a - 2);
            two = calcpref(tot - alltwos - 1, b - 1) - calcpref(tot - alltwos - 1, a - 2);
        }

        if (a == 0)
        {
            six = calcpref(tot - alltwos, b - 1);
            five = calcpref(tot, b);
        }
        else
        {
            six = calcpref(tot - alltwos, b - 1) - calcpref(tot - alltwos, a - 1);
            five = calcpref(tot, b) - calcpref(tot, a - 1);
        }
        six *= onlytwos + 2;
        six += onlytwos * nCr(tot - alltwos, a - 1);
        six += 2 * nCr(tot - alltwos, b);
        // debug(one, two, three, four, five, f.first, f.second);

        res += 2 * f.first * one;
        res -= f.second * two;
        res -= six;
        res += 3 * five;

        cout << (res % mod + mod) % mod << "\n";
    }
}
