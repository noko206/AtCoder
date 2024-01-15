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

using mint = modint998244353;

int main(){
	int n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	vector<vector<mint>> dp_t(n + 1, vector<mint>(n + 1, 0));
	vector<vector<mint>> dp_a(n + 1, vector<mint>(n + 1, 0));
	ll ip = inv_mod(p, 998244353);
	ll iq = inv_mod(q, 998244353);
	dp_t[a][0] = 1;
	dp_a[b][0] = 1;
	REP(i, a, n){
		REP(j, 1, p + 1){
			REP(k, n){
				dp_t[min(i + j, n)][k + 1] += dp_t[i][k] * ip;
			}
		}
	}
	REP(i, b, n){
		REP(j, 1, q + 1){
			REP(k, n){
				dp_a[min(i + j, n)][k + 1] += dp_a[i][k] * iq;
			}
		}
	}
	mint ans = 0;
	REP(i, 1, n + 1){
		mint tmp = 0;
		REP(j, n){
			tmp += dp_a[j][i - 1];
		}
		ans += dp_t[n][i] * tmp;
	}
	cout << ans.val() << endl;
	// REP(j, n + 1){
	// 	REP(i, n + 1){
	// 		cout << dp_t[i][j].val() << ' ';
	// 	}
	// 	cout << endl;
	// }
	// output("---");
	// REP(j, n + 1){
	// 	REP(i, n + 1){
	// 		cout << dp_a[i][j].val() << ' ';
	// 	}
	// 	cout << endl;
	// }
}