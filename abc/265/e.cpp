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

ll mod_pow(ll a, ll n, ll p) {
	if (n == 0) return 1;
	if (n == 1) return a % p;
	if (n % 2 == 1) return (a * mod_pow(a, n - 1, p)) % p;
	ll t = mod_pow(a, n / 2, p);
	return (t * t) % p;
}

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
	int n, m;
	cin >> n >> m;
	ll a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	map<pair<ll, ll>, bool> mp;
	REP(i, m){
		int x, y;
		cin >> x >> y;
		mp[{x, y}] = true;
	}
	int mod = MOD998244353;
	ll ans = mod_pow(3, n, mod);
	vector<ll> fact(n + 1); fact[0] = 1;
	vector<ll> ifact(n + 1); ifact[0] = mod_inv(1, mod);
	REP(i, n){
		fact[i + 1] = (i + 1) * fact[i];
		fact[i + 1] %= mod;
		ifact[i + 1] = mod_inv(fact[i + 1], mod);
	}
	REP(i, n + 1){
		REP(j, n + 1){
			REP(k, n + 1){
				if(i + j + k > n) continue;
				ll x = a * i + c * j + e * k;
				ll y = b * i + d * j + f * k;
				if(mp.find({x, y}) != mp.end()){
					ll tmp = fact[i + j + k];
					tmp *= ifact[i]; tmp %= mod;
					tmp *= ifact[j]; tmp %= mod;
					tmp *= ifact[k]; tmp %= mod;
					tmp *= mod_pow(3, n - (i + j + k), mod);
					tmp %= mod;
					ans -= tmp;
					ans += mod;
					ans %= mod;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}