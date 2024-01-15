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
const int MOD1000000007 = 1000000007;
const int MOD998244353 = 998244353;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
	int t;
	cin >> t;
	int mod = MOD998244353;
	vector<ll> pow26(1000000);
	pow26[0] = 1;
	REP(i, 1, 1000000){
		pow26[i] = pow26[i - 1] * 26;
		pow26[i] %= mod;
	}
	auto solve = [&]() -> ll {
		int n;
		string s;
		cin >> n >> s;
		int m = (n + 1) / 2;
		ll ans = 0;
		REP(i, m){
			ans += pow26[m - (i + 1)] * (s[i] - 'A');
			ans %= mod;
		}
		if(n % 2 == 0){
			string t = s.substr(0, m);
			string u = t;
			reverse(ALL(u));
			t += u;
			if(t <= s) ++ans;
		}
		else{
			string t = s.substr(0, m - 1);
			string u = t;
			reverse(ALL(u));
			t += s[m - 1];
			t += u;
			if(t <= s) ++ans;
		}
		ans %= mod;
		return ans;
	};
	vector<ll> ans(t);
	REP(i, t){
		ans[i] = solve();
	}
	REP(i, t){
		cout << ans[i] << endl;
	}
}