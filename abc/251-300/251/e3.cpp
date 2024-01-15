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
	int n;
	cin >> n;
	vector<int> a(n);
	int mi = INF;
	int idx = -1;
	REP(i, n){
		cin >> a[i];
		if(chmin(mi, a[i])) {
			idx = i;
		}
	}
	vector<bool> is_ok(n, false);
	ll ans = 0;
	ans += a[idx];
	is_ok[idx] = true;
	is_ok[(idx + 1) % n] = true;
	REP(i, 1, n){
		int j = (i + idx) % n;
		if (is_ok[j]) continue;
		if (a[j] + a[(j + 1) % n] < a[(j - 1 + n) % n]) {
			ans += a[j];
			is_ok[j] = true;
			is_ok[(j + 1) % n] = true;
		}
		else{
			ans += a[(j - 1 + n) % n];
			is_ok[j] = true;
		}
	}
	cout << ans << endl;
}