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
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	unordered_map<int, bool> mp;
	REP(i, k){
		cin >> a[i];
		--a[i];
		mp[a[i]] = true;
	}
	vector<int> x(n), y(n);
	REP(i, n){
		cin >> x[i] >> y[i];
	}
	ll ans = 0;
	// あかりを持っていない人
	REP(i, n){
		if(mp.find(i) != mp.end()) continue;
		// あかりを持っている人
		ll tmp = LLINF;
		REP(j, k){
			chmin(tmp, ((ll)(x[i] - x[a[j]]) * (x[i] - x[a[j]])) + ((ll)(y[i] - y[a[j]]) * (y[i] - y[a[j]])));
		}
		chmax(ans, tmp);
	}
	printf("%.9f\n", sqrt(ans));
}