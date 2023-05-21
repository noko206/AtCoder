#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int MOD1000000007 = 1000000007;
const int MOD998244353 = 998244353;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

struct BIT {
	int n;          // 配列の要素数(数列の要素数+1)
	vector<ll> bit;  // データの格納先
	BIT(int n_) : n(n_ + 1), bit(n, 0) {}
	void add(int i, ll x) {
		for (int idx = i; idx < n; idx += (idx & -idx)) {
			bit[idx] += x;
		}
	}
	ll sum(int i) {
		ll s(0);
		for (int idx = i; idx > 0; idx -= (idx & -idx)) {
			s += bit[idx];
		}
		return s;
	}
};

ll mod_inv(ll a, ll m) {
	ll b = m, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	int mod = 998244353;
	BIT bit1(200005), bit2(200005);
	vector<ll> dp(n + 1, 0);
	REP(i, n){
		ll low = bit2.sum(a[i]) * (ll)a[i]; low *= 2; low %= mod;
		ll high = bit1.sum(200005) - bit1.sum(a[i]); high *= 2; high %= mod;
		bit1.add(a[i], a[i]);
		bit2.add(a[i], 1);
		// cout << low << ' ' << high << endl;
		ll tmp = dp[i] * i; tmp %= mod; tmp *= i; tmp %= mod;
		tmp += low; tmp %= mod; tmp += high; tmp %= mod; tmp += a[i]; tmp %= mod;
		ll inv = mod_inv(i + 1, mod);
		tmp *= (inv * inv) % mod; tmp %= mod;
		dp[i + 1] = tmp;
	}
	REP(i, n){
		cout << dp[i + 1] << endl;
	}
}