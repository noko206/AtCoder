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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> b(n, vector<int>(m));
	REP(i, n) REP(j, m) cin >> b[i][j], --b[i][j];
	bool is_ok = true;
	REP(i, n){
		set<int> st;
		REP(j, m){
			st.insert(b[i][j] % 7);
		}
		if((int)st.size() != m) is_ok = false;
		REP(j, m - 1){
			if(b[i][j] % 7 != (b[i][j + 1] % 7) - 1) is_ok = false;
			if(b[i][j] != b[i][j + 1] - 1) is_ok = false;
		}
	}
	REP(j, m){
		set<int> st;
		REP(i, n){
			st.insert(b[i][j] % 7);
		}
		if((int)st.size() != 1) is_ok = false;
		REP(i, n - 1){
			if(b[i][j] != b[i + 1][j] - 7) is_ok = false;
		}
	}
	YesNo(is_ok);
}