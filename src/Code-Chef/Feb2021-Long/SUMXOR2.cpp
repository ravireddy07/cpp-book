// Problem Statement: https://www.codechef.com/FEB21B/problems/SUMXOR2/

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
#define mp make_pair
#define unmp unordered_map
#define pqi priority_queue<int>
#define pq priority_queue
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define yes printf("YES\n")
#define no printf("NO\n")
#define int long long
using namespace std;

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

const int N = 200007, mod = 998244353, md = 998244353;
using ld = long double;
struct base
{
	double x, y;
	base() { x = y = 0; }
	base(double x, double y) : x(x), y(y) {}
};
inline base operator+(base a, base b)
{
	return base(a.x + b.x, a.y + b.y);
}
inline base operator-(base a, base b)
{
	return base(a.x - b.x, a.y - b.y);
}
inline base operator*(base a, base b)
{
	return base(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
inline base conj(base a)
{
	return base(a.x, -a.y);
}
int lim = 1;
vector<base> starters = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};
const double PI = acosl(-1.0);
void checkXOR(int p)
{
	if (p <= lim)
		return;
	rev.resize(1 << p);
	for (int i = 0; i < (1 << p); i++)
		rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (p - 1));
	starters.resize(1 << p);
	while (lim < p)
	{
		double angle = 2 * PI / (1 << (lim + 1));
		for (int i = 1 << (lim - 1); i < (1 << lim); i++)
		{
			starters[i << 1] = starters[i];
			double angle_i = angle * (2 * i + 1 - (1 << lim));
			starters[(i << 1) + 1] = base(cos(angle_i), sin(angle_i));
		}
		lim++;
	}
}
void bitsN(vector<base> &a, int n = -1)
{
	if (n == -1)
		n = a.size();
	assert((n & (n - 1)) == 0);
	int zeros = __builtin_ctz(n);
	checkXOR(zeros);
	int shift = lim - zeros;
	for (int i = 0; i < n; i++)
		if (i < (rev[i] >> shift))
			swap(a[i], a[rev[i] >> shift]);
	for (int k = 1; k < n; k <<= 1)
	{
		for (int i = 0; i < n; i += 2 * k)
		{
			for (int j = 0; j < k; j++)
			{
				base z = a[i + j + k] * starters[j + k];
				a[i + j + k] = a[i + j] - z;
				a[i + j] = a[i + j] + z;
			}
		}
	}
}
vector<int> getMul(vector<int> &a, vector<int> &b, int eq = 0)
{
	int need = a.size() + b.size() - 1;
	int p = 0;
	while ((1 << p) < need)
		p++;
	checkXOR(p);
	int sz = 1 << p;
	vector<base> A, B;
	if (sz > (int)A.size())
		A.resize(sz);
	for (int i = 0; i < (int)a.size(); i++)
	{
		int x = (a[i] % mod + mod) % mod;
		A[i] = base(x & ((1 << 15) - 1), x >> 15);
	}
	fill(A.begin() + a.size(), A.begin() + sz, base{0, 0});
	bitsN(A, sz);
	if (sz > (int)B.size())
		B.resize(sz);
	if (eq)
		copy(A.begin(), A.begin() + sz, B.begin());
	else
	{
		for (int i = 0; i < (int)b.size(); i++)
		{
			int x = (b[i] % mod + mod) % mod;
			B[i] = base(x & ((1 << 15) - 1), x >> 15);
		}
		fill(B.begin() + b.size(), B.begin() + sz, base{0, 0});
		bitsN(B, sz);
	}
	double ratio = 0.25 / sz;
	base r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
	for (int i = 0; i <= (sz >> 1); i++)
	{
		int j = (sz - i) & (sz - 1);
		base a1 = (A[i] + conj(A[j])), a2 = (A[i] - conj(A[j])) * r2;
		base b1 = (B[i] + conj(B[j])) * r3, b2 = (B[i] - conj(B[j])) * r4;
		if (i != j)
		{
			base c1 = (A[j] + conj(A[i])), c2 = (A[j] - conj(A[i])) * r2;
			base d1 = (B[j] + conj(B[i])) * r3, d2 = (B[j] - conj(B[i])) * r4;
			A[i] = c1 * d1 + c2 * d2 * r5;
			B[i] = c1 * d2 + c2 * d1;
		}
		A[j] = a1 * b1 + a2 * b2 * r5;
		B[j] = a1 * b2 + a2 * b1;
	}
	bitsN(A, sz);
	bitsN(B, sz);
	vector<int> res(need);
	for (int i = 0; i < need; i++)
	{
		long long aa = A[i].x + 0.5;
		long long bb = B[i].x + 0.5;
		long long cc = A[i].y + 0.5;
		res[i] = (aa + ((bb % mod) << 15) + ((cc % mod) << 30)) % mod;
	}
	return res;
}
template <int32_t MOD>
struct modint
{
	int32_t value;
	modint() = default;
	modint(int32_t value_) : value(value_) {}
	inline modint<MOD> operator+(modint<MOD> other) const
	{
		int32_t c = this->value + other.value;
		return modint<MOD>(c >= MOD ? c - MOD : c);
	}
	inline modint<MOD> operator-(modint<MOD> other) const
	{
		int32_t c = this->value - other.value;
		return modint<MOD>(c < 0 ? c + MOD : c);
	}
	inline modint<MOD> operator*(modint<MOD> other) const
	{
		int32_t c = (int64_t)this->value * other.value % MOD;
		return modint<MOD>(c < 0 ? c + MOD : c);
	}
	inline modint<MOD> &operator+=(modint<MOD> other)
	{
		this->value += other.value;
		if (this->value >= MOD)
			this->value -= MOD;
		return *this;
	}
	inline modint<MOD> &operator-=(modint<MOD> other)
	{
		this->value -= other.value;
		if (this->value < 0)
			this->value += MOD;
		return *this;
	}
	inline modint<MOD> &operator*=(modint<MOD> other)
	{
		this->value = (int64_t)this->value * other.value % MOD;
		if (this->value < 0)
			this->value += MOD;
		return *this;
	}
	inline modint<MOD> operator-() const
	{
		return modint<MOD>(this->value ? MOD - this->value : 0);
	}
	modint<MOD> pow(uint64_t k) const
	{
		modint<MOD> x = *this, y = 1;
		for (; k; k >>= 1)
		{
			if (k & 1)
				y *= x;
			x *= x;
		}
		return y;
	}
	modint<MOD> inv() const { return pow(MOD - 2); }
	inline modint<MOD> operator/(modint<MOD> other) const
	{
		return *this * other.inv();
	}
	inline modint<MOD> operator/=(modint<MOD> other)
	{
		return *this *= other.inv();
	}
	inline bool operator==(modint<MOD> other) const
	{
		return value == other.value;
	}
	inline bool operator!=(modint<MOD> other) const
	{
		return value != other.value;
	}
	inline bool operator<(modint<MOD> other) const { return value < other.value; }
	inline bool operator>(modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD>
modint<MOD> operator*(int64_t value, modint<MOD> n)
{
	return modint<MOD>(value) * n;
}
template <int32_t MOD>
modint<MOD> operator*(int32_t value, modint<MOD> n)
{
	return modint<MOD>(value % MOD) * n;
}
template <int32_t MOD>
ostream &operator<<(ostream &out, modint<MOD> n)
{
	return out << n.value;
}
using mint = modint<mod>;
struct poly
{
	vector<mint> a;
	inline void normalize()
	{
		while ((int)a.size() && a.back() == 0)
			a.pop_back();
	}
	template <class... Args>
	poly(Args... args)
		: a(args...) {}
	poly(const initializer_list<mint> &x) : a(x.begin(), x.end()) {}
	int size() const { return (int)a.size(); }
	inline mint coef(const int i) const
	{
		return (i < a.size() && i >= 0) ? a[i] : mint(0);
	}
	mint operator[](const int i) const
	{
		return (i < a.size() && i >= 0) ? a[i] : mint(0);
	}
	bool is_zero() const
	{
		for (int i = 0; i < size(); i++)
			if (a[i] != 0)
				return 0;
		return 1;
	}
	poly operator+(const poly &x) const
	{
		int n = max(size(), x.size());
		vector<mint> ans(n);
		for (int i = 0; i < n; i++)
			ans[i] = coef(i) + x.coef(i);
		while ((int)ans.size() && ans.back() == 0)
			ans.pop_back();
		return ans;
	}
	poly operator-(const poly &x) const
	{
		int n = max(size(), x.size());
		vector<mint> ans(n);
		for (int i = 0; i < n; i++)
			ans[i] = coef(i) - x.coef(i);
		while ((int)ans.size() && ans.back() == 0)
			ans.pop_back();
		return ans;
	}
	poly operator*(const poly &b) const
	{
		if (is_zero() || b.is_zero())
			return {};
		vector<int> A, B;
		for (auto x : a)
			A.push_back(x.value);
		for (auto x : b.a)
			B.push_back(x.value);
		auto res = getMul(A, B, (A == B));
		vector<mint> ans;
		for (auto x : res)
			ans.push_back(mint(x));
		while ((int)ans.size() && ans.back() == 0)
			ans.pop_back();
		return ans;
	}
	poly operator*(const mint &x) const
	{
		int n = size();
		vector<mint> ans(n);
		for (int i = 0; i < n; i++)
			ans[i] = a[i] * x;
		return ans;
	}
	poly operator/(const mint &x) const { return (*this) * x.inv(); }
	poly &operator+=(const poly &x) { return *this = (*this) + x; }
	poly &operator-=(const poly &x) { return *this = (*this) - x; }
	poly &operator*=(const poly &x) { return *this = (*this) * x; }
	poly &operator*=(const mint &x) { return *this = (*this) * x; }
	poly &operator/=(const mint &x) { return *this = (*this) / x; }
	poly mod_xk(int k) const { return {a.begin(), a.begin() + min(k, size())}; }
	poly mul_xk(int k) const
	{
		poly ans(*this);
		ans.a.insert(ans.a.begin(), k, 0);
		return ans;
	}
	poly div_xk(int k) const
	{
		return vector<mint>(a.begin() + min(k, (int)a.size()), a.end());
	}
	poly substr(int l, int r) const
	{
		l = min(l, size());
		r = min(r, size());
		return vector<mint>(a.begin() + l, a.begin() + r);
	}
	poly reverse_it(int n, bool rev = 0) const
	{
		poly ans(*this);
		if (rev)
		{
			ans.a.resize(max(n, (int)ans.a.size()));
		}
		reverse(ans.a.begin(), ans.a.end());
		return ans.mod_xk(n);
	}
	poly differentiate() const
	{
		int n = size();
		vector<mint> ans(n);
		for (int i = 1; i < size(); i++)
			ans[i - 1] = coef(i) * i;
		return ans;
	}
	poly inverse(int n) const
	{
		assert(!is_zero());
		assert(a[0] != 0);
		poly ans{mint(1) / a[0]};
		for (int i = 1; i < n; i *= 2)
		{
			ans = (ans * mint(2) - ans * ans * mod_xk(2 * i)).mod_xk(2 * i);
		}
		return ans.mod_xk(n);
	}
	pair<poly, poly> divmod_slow(const poly &b) const
	{
		vector<mint> A(a);
		vector<mint> ans;
		while (A.size() >= b.a.size())
		{
			ans.push_back(A.back() / b.a.back());
			if (ans.back() != mint(0))
			{
				for (size_t i = 0; i < b.a.size(); i++)
				{
					A[A.size() - i - 1] -= ans.back() * b.a[b.a.size() - i - 1];
				}
			}
			A.pop_back();
		}
		reverse(ans.begin(), ans.end());
		return {ans, A};
	}
	pair<poly, poly> divmod(const poly &b) const
	{
		if (size() < b.size())
			return {poly{0}, *this};
		int d = size() - b.size();
		if (min(d, b.size()) < 250)
			return divmod_slow(b);
		poly D = (reverse_it(d + 1) * b.reverse_it(d + 1).inverse(d + 1))
		         .mod_xk(d + 1)
		         .reverse_it(d + 1, 1);
		return {D, *this - (D * b)};
	}
	poly operator/(const poly &t) const { return divmod(t).first; }
	poly operator%(const poly &t) const { return divmod(t).second; }
	poly &operator/=(const poly &t) { return *this = divmod(t).first; }
	poly &operator%=(const poly &t) { return *this = divmod(t).second; }
	mint eval(mint x)
	{
		mint ans(0);
		for (int i = (int)size() - 1; i >= 0; i--)
		{
			ans *= x;
			ans += a[i];
		}
		return ans;
	}
	poly build(vector<poly> &ans, int v, int l, int r, vector<mint> &vec)
	{
		if (l == r)
			return ans[v] = poly({ -vec[l], 1});
		int mid = l + r >> 1;
		return ans[v] = build(ans, 2 * v, l, mid, vec) *
		                build(ans, 2 * v + 1, mid + 1, r, vec);
	}
	vector<mint> eval(vector<poly> &tree,
	                  int v,
	                  int l,
	                  int r,
	                  vector<mint> &vec)
	{
		if (l == r)
			return {eval(vec[l])};
		if (size() < 100)
		{
			vector<mint> ans(r - l + 1, 0);
			for (int i = l; i <= r; i++)
				ans[i - l] = eval(vec[i]);
			return ans;
		}
		int mid = l + r >> 1;
		auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, mid, vec);
		auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, mid + 1, r, vec);
		A.insert(A.end(), B.begin(), B.end());
		return A;
	}
	vector<mint> eval(vector<mint> x)
	{
		int n = x.size();
		if (is_zero())
			return vector<mint>(n, mint(0));
		vector<poly> tree(4 * n);
		build(tree, 1, 0, n - 1, x);
		return eval(tree, 1, 0, n - 1, x);
	}
};
poly mul(int l, int r, vector<mint> &a)
{
	if (l == r)
		return poly({ -a[l], 1});
	int mid = l + r >> 1;
	return mul(l, mid, a) * mul(mid + 1, r, a);
}
const int p = 998244353;
int mul(int a, int b)
{
	return (1LL * a * b) % p;
}
int add(int a, int b)
{
	int s = (a + b);
	if (s >= p)
		s -= p;
	return s;
}
int sub(int a, int b)
{
	int s = (a + p - b);
	if (s >= p)
		s -= p;
	return s;
}
int getNum(int a, int deg)
{
	if (deg == 0)
		return 1;
	if (deg % 2 == 1)
		return mul(a, getNum(a, deg - 1));
	int t = getNum(a, deg / 2);
	return mul(t, t);
}
int inv(int n)
{
	return getNum(n, p - 2);
}
vector<int> f1(N), f2(N);
void setup()
{
	f1[0] = 1;
	for (int i = 1; i < N; i++)
		f1[i] = mul(f1[i - 1], i);
	f2[N - 1] = inv(f1[N - 1]);
	for (int i = N - 2; i >= 0; i--)
		f2[i] = mul(f2[i + 1], i + 1);
}
int C(int n, int k)
{
	if (n < k)
		return 0;
	return mul(f1[n], mul(f2[k], f2[n - k]));
}
int temp(int x)
{
	if (x == 0)
		return 1;
	int cnt = x / p;
	int res = mul(f1[x % p], temp(cnt));
	if (cnt % 2 == 1)
		res = sub(0, res);
	return res;
}
int C1(int x, int y)
{
	int x1 = x;
	int y1 = y;
	while (y1)
	{
		if (y1 % p > x1 % p)
			return 0;
		x1 /= p;
		y1 /= p;
	}
	return mul(temp(x), inv(mul(temp(y), temp(x - y))));
}

int32_t main()
{
	setup();
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	vector<vector<int>> bin(n + 1, vector<int>(32, 0));
	vector<int> ct(32, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if ((v[i] >> j) & 1)
				ct[j]++;
		}
	}
	for (int j = 0; j < 32; j++)
	{
		vector<int> A(ct[j] + 1, 0);
		vector<int> B(n - ct[j] + 1, 0);
		for (int i = 0; i <= n; i++)
		{
			if (i % 2 && i <= ct[j])
				A[i] = C(ct[j], i);
			if (i <= n - ct[j])
				B[i] = C(n - ct[j], i);
		}
		vector<int> v3 = getMul(A, B);
		for (int i = 1; i <= n; i++)
		{
			bin[i][j] = bin[i - 1][j] + v3[i];
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int m;
		cin >> m;
		int ans = 0;
		for (int i = 0; i < 32; i++)
		{
			ans += (bin[m][i] % md * (1ll << i) % md) % md;
			ans %= md;
		}
		printf("%d\n", ans);
	}
	return 0;
}
