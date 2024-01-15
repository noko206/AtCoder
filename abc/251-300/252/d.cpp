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
	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> cnt(200005, 0);
	REP(i, n){
		cin >> a[i];
		++cnt[a[i]];
	}
	--cnt[a[0]];
	ll ans = 0;
	ll com = (n - 1) * (n - 2) / 2;
	REP(i, 1, 200001){
		if(cnt[i] == 0) continue;
		if(i == a[0]){
			com -= cnt[i] * (n - 1 - cnt[i]);
		}
		com -= cnt[i] * (cnt[i] - 1) / 2;
	}
	ans += com;
	REP(i, 1, n - 2){
		com -= (n - i) * (n - i - 1) / 2;
		com += cnt[a[i - 1]] * (n - i - cnt[a[i - 1]]);
		if (a[i - 1] != a[i]) {
			com += cnt[a[i - 1]] * (cnt[a[i - 1]] - 1) / 2;
		}
		com += cnt[a[i]] * (cnt[a[i]] - 1) / 2;
		--cnt[a[i]];
		com += (n - i - 1) * (n - i - 2) / 2;
		if (a[i - 1] != a[i]) {
			com -= cnt[a[i - 1]] * (cnt[a[i - 1]] - 1) / 2;
		}
		com -= cnt[a[i]] * (n - i - 1 - cnt[a[i]]);
		com -= cnt[a[i]] * (cnt[a[i]] - 1) / 2;
		ans += com;
	}
	cout << ans << endl;
}