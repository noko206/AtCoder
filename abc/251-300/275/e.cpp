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

ll dp[1005][1005];

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
	ll n, m, k;
	cin >> n >> m >> k;
	ll mod = MOD998244353;
	ll inv = mod_inv(m, mod);
	dp[0][0] = 1;
	REP(i, k){
		REP(j, n){
			REP(l, 1, m + 1){
				if(j + l <= n){
					dp[i + 1][j + l] += (dp[i][j] * inv) % mod;
					dp[i + 1][j + l] %= mod;
				}
				else{
					dp[i + 1][n - (j + l - n)] += (dp[i][j] * inv) % mod;
					dp[i + 1][n - (j + l - n)] %= mod;
				}
			}
		}
	}
	ll ans = 0;
	REP(i, k){
		ans += dp[i + 1][n];
		ans %= mod;
	}
	cout << ans << endl;
}