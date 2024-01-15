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

int main(){
	int n, p;
	cin >> n >> p;
	vector<ll> fact(n + 1), ifact(n + 1);
	ll mod = 998244353;
	ll tmp = 1;
	REP(i, n + 1){
		if(i != 0){
			tmp *= (ll)i;
			tmp %= mod;
		}
		fact[i] = tmp;
		ifact[i] = mod_inv(tmp, mod);
	}
	vector<ll> one_p(n + 1), two_p(n + 1);
	ll two_base = (ll)p * mod_inv(100, mod); two_base %= mod;
	ll one_base = 1LL - two_base + mod; one_base %= mod;
	ll one_tmp = 1;
	ll two_tmp = 1;
	REP(i, n + 1){
		one_p[i] = one_tmp;
		two_p[i] = two_tmp;
		one_tmp *= one_base; one_tmp %= mod;
		two_tmp *= two_base; two_tmp %= mod;
	}
	ll ans = 0;
	auto nCk = [&](ll n, ll k) -> ll {
		ll res = fact[n];
		res *= ifact[k]; res %= mod;
		res *= ifact[n - k]; res %= mod;
		return res;
	};
	REP(one_cnt, n + 1){
		ll two_cnt = (n - one_cnt + 1) / 2;
		if(n == one_cnt + two_cnt * 2){
			tmp = nCk(one_cnt + two_cnt, one_cnt);
		}
		else{
			tmp = nCk(one_cnt + two_cnt - 1, one_cnt);
		}
		tmp *= one_p[one_cnt]; tmp %= mod;
		tmp *= two_p[two_cnt]; tmp %= mod;
		tmp *= one_cnt + two_cnt; tmp %= mod;
		ans += tmp; ans %= mod;
	}
	cout << ans << endl;
}