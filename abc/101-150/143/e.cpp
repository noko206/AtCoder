#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define _RREP(i,n) RREPI(i,n,0)
#define RREPI(i,a,b) for(int i=int(a);i>=int(b);--i)
#define RREP(...) _overload3(__VA_ARGS__,RREPI,_RREP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); }} init;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

int main(){
	int n, m, l;
	cin >> n >> m >> l;
	vector<vector<ll>> dp(n, vector<ll>(n, INF64));
	REP(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		dp[a][b] = c;
		dp[b][a] = c;
	}
	REP(i, n) dp[i][i] = 0;
	REP(k, n){
		REP(i, n){
			REP(j, n){
				chmin(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	REP(i, n){
		REP(j, n){
			if(i == j) continue;
			if(dp[i][j] <= l) dp[i][j] = 1;
			else dp[i][j] = INF64;
		}
	}
	REP(k, n){
		REP(i, n){
			REP(j, n){
				chmin(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	int q;
	cin >> q;
	vector<ll> ans(q);
	REP(i, q){
		int s, t;
		cin >> s >> t;
		--s, --t;
		ll tmp = dp[s][t];
		if(tmp == INF64) tmp = -1;
		else tmp -= 1;
		ans[i] = tmp;
	}
	REP(i, q) output(ans[i]);
	output("\n");
}