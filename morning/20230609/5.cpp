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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(n, vector<int>(n));
	REP(i, n) REP(j, n) cin >> a[i][j];
	// 階乗を前計算
	vector<mint> fact(100005, 1);
	REP(i, 100000) fact[i + 1] = fact[i] * (i + 1);
	// 行固定
	dsu uf1(n);
	REP(x, n){
		REP(y, x){
			bool is_ok = true;
			REP(i, n){
				if(a[i][x] + a[i][y] > k) is_ok = false;
			}
			if(is_ok){
				uf1.merge(x, y);
			}
		}
	}
	mint col_ans = 1;
	for(auto v : uf1.groups()){
		col_ans *= fact[(int)v.size()];
	}
	// 列固定
	dsu uf2(n);
	REP(x, n){
		REP(y, x){
			bool is_ok = true;
			REP(j, n){
				if(a[x][j] + a[y][j] > k) is_ok = false;
			}
			if(is_ok){
				uf2.merge(x, y);
			}
		}
	}
	mint row_ans = 1;
	for(auto v : uf2.groups()){
		row_ans *= fact[(int)v.size()];
	}
	mint ans = col_ans * row_ans;
	output(ans.val());
}