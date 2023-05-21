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

int op(int a, int b) {
	return max(a, b);
};

int e() {
	return -1;
};

int target;

bool f(int v) {
	return v < target;
}

int main(){
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	segtree<int, op, e> seg(a);
	vector<int> ans;
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int x, v;
			cin >> x >> v;
			--x;
			seg.set(x, v);
		}
		if(t == 2){
			int l, r;
			cin >> l >> r;
			--l;
			ans.push_back(seg.prod(l, r));
		}
		if(t == 3){
			int x;
			cin >> x >> target;
			--x;
			ans.push_back(seg.max_right<f>(x) + 1);
		}
	}
	output(ans);
}