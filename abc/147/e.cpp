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

struct DP {
	ll red;
	ll blue;
};

DP dp[85][85][2];

int main(){
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	vector<vector<int>> b(h, vector<int>(w));
	REP(i, h) REP(j, w) cin >> a[i][j];
	REP(i, h) REP(j, w) cin >> b[i][j];
	REP(i, h){
		REP(j, w){
			REP(k, 2){
				ll tmp = INF64;
				int red = k ? b[i][j] : a[i][j];
				int blue = k ? a[i][j] : b[i][j];
				dp[i][j][k].red = red;
				dp[i][j][k].blue = blue;
				REP(l, 2){
					if(i - 1 >= 0){
						ll tmp_red = dp[i - 1][j][l].red + red;
						ll tmp_blue = dp[i - 1][j][l].blue + blue;
						if(chmin(tmp, abs(tmp_red - tmp_blue))){
							dp[i][j][k].red = tmp_red;
							dp[i][j][k].blue = tmp_blue;
						}
					}
					if(j - 1 >= 0){
						ll tmp_red = dp[i][j - 1][l].red + red;
						ll tmp_blue = dp[i][j - 1][l].blue + blue;
						if(chmin(tmp, abs(tmp_red - tmp_blue))){
							dp[i][j][k].red = tmp_red;
							dp[i][j][k].blue = tmp_blue;
						}
					}
				}
			}
		}
	}
	ll ans = INF64;
	REP(k, 2){
		chmin(ans, abs(dp[h - 1][w - 1][k].red - dp[h - 1][w - 1][k].blue));
	}
	output(ans);
}