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

ll solve(){
	string s;
	cin >> s;
	int n = s.length();
	ll ans = 0;
	REP(i, 2, n + 1){
		if(n % i != 0) continue;
		string t = s.substr(0, n / i);
		string u = "";
		REP(j, i){
			u += t;
		}
		ll u_ll = stoll(u);
		ll s_ll = stoll(s);
		if(u_ll <= s_ll) {
			chmax(ans, u_ll);
			continue;
		}
		ll t_ll = stoll(t);
		--t_ll;
		t = to_string(t_ll);
		u = "";
		REP(j, i){
			u += t;
		}
		u_ll = stoll(u);
		chmax(ans, u_ll);
	}
	ll x = 0;
	REP(i, n - 1){
		x *= 10;
		x += 9;
	}
	chmax(ans, x);
	return ans;
}

int main(){
	int t;
	cin >> t;
	vector<ll> ans(t);
	REP(i, t){
		ans[i] = solve();
	}
	REP(i, t){
		cout << ans[i] << endl;
	}
}