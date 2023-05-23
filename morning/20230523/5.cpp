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
mint dp[1005][1 << 10][10];

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	REP(i, n){
		int c = s[i] - 'A';
		REP(j, 1 << 10){
			REP(k, 10){
				if(j & (1 << c)){
					if(k == c){
						dp[i + 1][j][k] += dp[i][j][k];
					}
				}
				else{
					dp[i + 1][j | (1 << c)][c] += dp[i][j][k];
				}
				dp[i + 1][j][k] += dp[i][j][k];
			}
		}
		// 初手でcに行く遷移
		++dp[i + 1][1 << c][c];
	}
	mint ans = 0;
	REP(i, 1 << 10){
		REP(j, 10){
			ans += dp[n][i][j];
		}
	}
	output(ans.val());
}