#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
	ll x, a, d, n;
	cin >> x >> a >> d >> n;
	if(d < 0){
		a += (n - 1) * d;
		d *= -1;
	}
	ll ok = -1;
	ll ng = n + 1;
	while(ng - ok != 1){
		ll mid = (ok + ng) / 2;
		if(a + (mid * d) < x){
			ok = mid;
		}
		else{
			ng = mid;
		}
	}
	if(ok == -1){
		cout << a - x << endl;
	}
	else if(ok == n){
		cout << x - (a + (d * (n - 1))) << endl;
	}
	else{
		ll ans = x - (a + (d * ok));
		chmin(ans, (a + (d * (ok + 1))) - x);
		cout << ans << endl;
	}
}