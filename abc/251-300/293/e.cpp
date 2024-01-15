#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

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
	ll a, x, m;
	cin >> a >> x >> m;
	if(a == 1){
		cout << x % m << endl;
		return 0;
	}
	ll tmp1 = (mod_pow(a % m, x, m) - 1 + m) % m;
	ll tmp2 = mod_inv(a - 1, m);
	ll ans = tmp1 * tmp2; ans %= m;
	cout << ans << endl;
}