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

const ll mod = MOD998244353;
ll n, m;

ll f(ll a, ll b, ll c, ll d){
	ll ans = (a - 1) * m + c; ans %= mod;
	ans *= d - c + 1; ans %= mod;
	ll tmp = (d - c + 1) * (d - c + 2) / 2; tmp %= mod;
	ans += tmp; ans %= mod;
	ans /= 2;
	return ans;
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
	cin >> n >> m;
	int q;
	cin >> q;
	vector<ll> ans(q);
	REP(i, q){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll h = (b - a + 1);
		ll w = (d - c + 1);
		if(h % 2 == 0){
			if(w % 2 == 0){
				ans[i] = f(a, b, c, d);
			}
			else{
				ll tmp = 0;
				if((a + d) % 2 == 1){
					++a;
				}
				tmp += 2 * a + ((h / 2) - 1) * 2 * m; tmp %= mod;
				tmp *= h / 2; tmp %= mod;
				tmp *= mod_inv(2, mod); tmp %= mod;
				tmp += f(a, b, c, d - 1); tmp %= mod;
				ans[i] = tmp;
			}
		}
		else{
			if(w % 2 == 0){
				ll tmp = 0;
				if((c + b) % 2 == 1){
					++c;
				}
				tmp += 2 * c + ((w / 2) - 1) * 2; tmp %= mod;
				tmp *= w / 2; tmp %= mod;
				tmp *= mod_inv(2, mod); tmp %= mod;
				tmp += f(a, b - 1, c, d); tmp %= mod;
				ans[i] = tmp;
			}
			else{
				ll tmp1 = 0;
				if((a + d) % 2 == 1){
					++a;
				}
				tmp1 += 2 * a + ((h / 2) - 1) * 2 * m; tmp1 %= mod;
				tmp1 *= h / 2; tmp1 %= mod;
				tmp1 *= mod_inv(2, mod); tmp1 %= mod;

				ll tmp2 = 0;
				if((c + b) % 2 == 1){
					++c;
				}
				tmp2 += 2 * c + ((w / 2) - 1) * 2; tmp2 %= mod;
				tmp2 *= w / 2; tmp2 %= mod;
				tmp2 *= mod_inv(2, mod); tmp2 %= mod;

				ll tmp3 = tmp1 + tmp2; tmp3 %= mod;
				if((b + d) % 2 == 0){
					tmp3 -= (b - 1) * m + d; tmp3 %= mod;
					tmp3 += mod; tmp3 %= mod;
				}

				tmp3 += f(a, b - 1, c, d - 1); tmp3 %= mod;
				ans[i] = tmp3;
			}
		}
	}
	REP(i, q){
		cout << ans[i] << endl;
	}
}