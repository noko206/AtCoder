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
	ll w, h, n, A, B;
	cin >> w >> h;
	cin >> n;
	vector<ll> p(n), q(n);
	REP(i, n) cin >> p[i] >> q[i];
	cin >> A;
	vector<ll> a(A);
	REP(i, A) cin >> a[i];
	cin >> B;
	vector<ll> b(B);
	REP(i, B) cin >> b[i];

	map<pair<int, int>, int> cnt;
	REP(i, n){
		int ai = lower_bound(ALL(a), p[i]) - a.begin();
		int bi= lower_bound(ALL(b), q[i]) - b.begin();
		++cnt[{ai, bi}];
	}
	int mn = n, mx = 0;
	if((ll)cnt.size() < (A + 1) * (B + 1)) mn = 0;
	for(auto v : cnt){
		chmin(mn, v.second);
		chmax(mx, v.second);
	}
	output(mn, mx);
}