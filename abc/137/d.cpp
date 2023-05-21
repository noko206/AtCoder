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

int op(int a, int b){
	return min(a, b);
}

int e(){
	return INF32;
}

bool f(int v){
	return v != 0;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	REP(i, n) cin >> a[i] >> b[i];
	vector<pair<int, int>> ba(n);
	REP(i, n) ba[i] = {-b[i], a[i]};
	sort(ALL(ba));
	vector<int> tmp(m, 0);
	segtree<int, op, e> seg(tmp);
	ll ans = 0;
	REP(i, n){
		int pb = ba[i].first;
		int pa = ba[i].second;
		if(m - pa < 0) continue;
		if(seg.get(m - pa) == 0){
			seg.set(m - pa, 1);
			ans += pb;
		}
		else{
			int idx = seg.min_left(m - pa + 1, f) - 1;
			//output(idx);
			if(idx < 0) continue;
			seg.set(idx, 1);
			ans += pb;
		}
	}
	output(-ans);
}