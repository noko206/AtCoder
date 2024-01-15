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

int main(){
	ll n, m;
	cin >> n >> m;
	ll ans = INF64;
	ll base = (ll)sqrtl(m);
	REP(i, 10000000){
		ll a = base + i;
		if(a <= n){
			ll b = (m + a - 1) / a;
			if(b <= n){
				chmin(ans, a * b);
			}
		}
		a = base - i;
		if(a <= n && a >= 1){
			ll b = (m + a - 1) / a;
			if(b <= n){
				chmin(ans, a * b);
			}
		}
	}
	if(ans == INF64) cout << -1 << endl;
	else cout << ans << endl;
}