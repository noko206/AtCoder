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
const int MOD = 1000000007;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
	int n;
	string x;
	cin >> n >> x;
	reverse(ALL(x));
	auto dfs = [&](auto &dfs, int v, int cnt = 0) -> int{
		if(v == 0) return cnt;
		return dfs(dfs, v % __builtin_popcount(v), cnt + 1);
	};
	vector<int> dp(n);
	REP(i, n){
		dp[i] = dfs(dfs, i);
	}
	int cnt = 0;
	REP(i, x.length()){
		if(x[i] == '1'){
			++cnt;
		}
	}
	vector<ll> twomod_plus(n), twomod_minus(n);
	twomod_plus[0] = 1 % (cnt + 1);
	twomod_minus[0] = 1 % max(cnt - 1, 1);
	REP(i, n - 1){
		twomod_plus[i + 1] = twomod_plus[i] * 2;
		twomod_minus[i + 1] = twomod_minus[i] * 2;
		twomod_plus[i + 1] %= cnt + 1;
		twomod_minus[i + 1] %= max(cnt - 1, 1);
	}
	ll amari_plus = 0;
	ll amari_minus = 0;
	REP(i, n){
		if(x[i] == '1'){
			amari_plus += twomod_plus[i];
			amari_minus += twomod_minus[i];
			amari_plus %= cnt + 1;
			amari_minus %= max(cnt - 1, 1);
		}
	}
	vector<ll> ans(n);
	REP(i, n){
		ll amari;
		if(x[i] == '1'){
			if(cnt - 1 == 0){
				ans[i] = 0;
				continue;
			}
			amari = amari_minus - twomod_minus[i] + cnt - 1;
			amari %= cnt - 1;
			ans[i] = dp[amari] + 1;
		}
		else{
			amari = amari_plus + twomod_plus[i];
			amari %= cnt + 1;
			ans[i] = dp[amari] + 1;
		}
	}
	reverse(ALL(ans));
	REP(i, n){
		cout << ans[i] << endl;
	}
}