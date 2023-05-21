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

ll dp[200005];

int main(){
	int n;
	cin >> n;
	vector<int> a(n - 1);
	REP(i, n - 1){
		cin >> a[i];
	}
	dp[n - 1] = 0;
	vector<ll> tot(n + 1);
	tot[n] = 0;
	tot[n - 1] = 0;
	int mod = MOD998244353;
	for(int i = n - 2; i >= 0; --i){
		ll tmp, ans;
		tmp = tot[i + 1] - tot[i + a[i] + 1];
		tmp += mod;
		tmp %= mod;
		tmp *= mod_inv(a[i], mod);
		tmp %= mod;
		ans = tmp;
		tmp = a[i] + 1;
		tmp %= mod;
		tmp *= mod_inv(a[i], mod);
		tmp %= mod;
		ans += tmp;
		ans %= mod;
		dp[i] = ans;
		tot[i] = tot[i + 1] + dp[i];
		tot[i] %= mod;
	}
	cout << dp[0] << endl;
}