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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	REP(i, n) cin >> a[i], --a[i];
	REP(i, n) cin >> b[i], --b[i];
	vector<int> tmp_a = a, tmp_b = b;
	sort(ALL(tmp_a));
	sort(ALL(tmp_b));
	vector<int> cnt(n, 0);
	REP(i, n){
		if(tmp_a[i] != tmp_b[i]){
			cout << "No" << endl;
			return 0;
		}
		++cnt[a[i]];
	}
	REP(i, n){
		if(cnt[i] >= 2){
			cout << "Yes" << endl;
			return 0;
		}
	}
	scc_graph ga(n), gb(n);
	REP(i, n){
		ga.add_edge(i, a[i]);
		gb.add_edge(i, b[i]);
	}
	YesNo(ga.scc().size() % 2 == gb.scc().size() % 2);
}