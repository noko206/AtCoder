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

ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }

unordered_map<ll, ll> prime_factorize(long long N) {
	unordered_map<ll, ll> res;
	for (long long a = 2; a * a <= N; ++a) {
		if (N % a != 0) continue;
		long long ex = 0; // 指数

		// 割れる限り割り続ける
		while (N % a == 0) {
			++ex;
			N /= a;
		}

		// その結果を push
		res[a] = ex;
	}

	// 最後に残った数について
	if (N != 1) res[N] = 1;
	return res;
}

int main(){
	ll a, b;
	cin >> a >> b;
	if(a == b){
		cout << 1 << endl;
		return 0;
	}
	if(a > b) swap(a, b);
	ll g = gcd(a, b);
	a /= g;
	b /= g;
	ll ans = 0;
	unordered_map<ll, ll> pf = prime_factorize(abs(a - b));
	while(a > 0 && b > 0){
		ll mi = INF64;
		ll idx = -1;
		for(auto v : pf){
			ll p = v.first;
			if(chmin(mi, a - p * (a / p))){
				idx = p;
			}
		}
		if(idx == -1){
			if(abs(a - b) == 1) {
				ans += min(a, b);
				break;
			}
			pf = prime_factorize(abs(a - b));
			continue;
		}
		--pf[idx];
		if(pf[idx] == 0) pf.erase(idx);
		a -= mi;
		b -= mi;
		ans += mi;
		if(a <= 0 || b <= 0) break;
		g = gcd(a, b);
		a /= g;
		b /= g;
	}
	cout << ans << endl;
}