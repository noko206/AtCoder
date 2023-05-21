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
	REP(i, n){
		cin >> a[i];
	}
	vector<bool> is_ok(n, false);
	ll ans = 0;
	REP(i, n){
		if (is_ok[i] || is_ok[(i + 1) % n]) continue;
		if (a[(i - 1 + n) % n] >= a[i] && a[i] <= a[(i + 1) % n]) {
			ans += a[i];
			is_ok[i] = true;
			is_ok[i + 1] = true;
		}
	}
	REP(i, n){
		cout << (int)is_ok[i] << ' ';
	}
	cout << endl;
	cout << ans << endl;
	REP(i, n){
		if (is_ok[i]) continue;
		if (is_ok[(i + 1) % n]){
			if (a[(i - 1 + n) % n] < a[i]) {
				ans += a[(i - 1 + n) % n];
				is_ok[(i - 1 + n) % n] = true;
				is_ok[i] = true;
			}
			else{
				ans += a[i];
				is_ok[i] = true;
				is_ok[(i + 1) % n] = true;
			}
		}
		else {
			if (a[(i - 1 + n) % n] + a[(i + 1) % n] < a[i]) {
				ans += a[(i - 1 + n) % n] + a[(i + 1) % n];
				is_ok[(i - 1 + n) % n] = true;
				is_ok[i] = true;
				is_ok[(i + 1) % n] = true;
			}
			else{
				ans += a[i];
				is_ok[i] = true;
				is_ok[(i + 1) % n] = true;
			}
		}
	}
	cout << ans << endl;
}